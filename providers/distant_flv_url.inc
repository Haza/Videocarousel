<?php

/**
 * @file
 *   This is an include file used by emfield.module.
 */

function _emvideo_distant_flv_url_default_types() {
  return array('flv');
}

function emvideo_distant_flv_url_info() {
  $name = t('Distant FLV URL');
  $features = array(
    array(t('Thumbnails'), t('No'), ''),
    array(t('Autoplay'), t('Yes'), ''),
    array(t('RSS attachment'), t('No'), ''),
  );
  return array(
    'provider' => 'distant_flv_url',
    'name' => $name,
    'url' => '',
    'settings_description' => t('These settings specifically affect videos displayed from custom URLs. When a field uses a URL it determines to be a link directly to a video file, it will embed that file into the content.'),
    'supported_features' => $features,
    'weight' => 9,
  );
}

function emvideo_distant_flv_url_settings() {
  $options = array(
    'flv' => t('Flash Video (flv)'),
  );
  $form = array();
  $form['emvideo_distant_flv_url_supported_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Supported Types'),
    '#options' => $options,
    '#default_value' => variable_get('emvideo_distant_flv_url_supported_types', _emvideo_distant_flv_url_default_types()),
    '#description' => t('Select the video types you wish to support. When a custom url with that type is entered into an embedded video field, it will be parsed and displayed appropriately. If a type is not supported, then it will be ignored.'),
  );
  return $form;
}

function _emvideo_distant_flv_url_implode_types() {
  return implode('|', variable_get('emvideo_distant_flv_url_supported_types', _emvideo_distant_flv_url_default_types()));
}

function emvideo_distant_flv_url_extract($embed = '') {
  $types = _emvideo_distant_flv_url_implode_types();
  $baseurl = preg_quote(url(null, array('absolute' => TRUE)), '@');

  return array(
    '@' . $baseurl . '(.*\.(?:' . $types . ')' . '(\?.*)?)@i',
    '@(.*\.(?:'. $types .')(\?.*)?)@i',
    '@'. $baseurl.'(.*(?:xspf))@i',
    '@(.*(?:xspf))@i',
  );
}

function emvideo_distant_flv_url_data($field, $item) {
  $data = array();
  // adding the version control
  $data['emvideo_distant_flv_url_data_version'] = 1;

  // attempt to get info from headers
  $response = emfield_request_header('distant_flv_url', $item['embed']);

  if ($response->code == 200) {
    $data['url'] = $item['embed'];
    $data['size'] = $response->headers['Content-Length'];
    $data['mime'] = $response->headers['Content-Type'];
  }
  // @todo replace ['type'] with converted mime info if available
  $types = _emvideo_distant_flv_url_implode_types();
  $regex = '@\.('. $types .')$@i';
  if (preg_match($regex, $item['embed'], $matches)) {
    $data['type'] = $matches[1];
  }
  return $data;
}

/**
 * hook emfield_PROVIDER_rss
 */
function emvideo_distant_flv_url_rss($item, $teaser = NULL) {
  if ($item['value']) {
    if ($item['data']['emvideo_distant_flv_url_data_version'] >= 1) {
      $data = $item['data'];
    }
    else {
      $data = emvideo_distant_flv_url_data(NULL, $item);
    }

    $file = array();
    if ($data['size'] > 0) {
      $file['filepath'] = $data['url'];
      $file['filesize'] = $data['size'];
      $file['filemime'] = $data['mime'];
    }

    return $file;
  }
}


function emvideo_distant_flv_url_embedded_link($video_code) {
  return $video_code;
}

function theme_emvideo_distant_flv_url_embedded_video($type, $url, $width, $height, $autoplay = FALSE, $field = NULL, $item = NULL, $options = array()) {

    $height = 470;
    $width = 383;
    if (variable_get('emfield_swfobject', FALSE) && (module_exists('swfobject_api') || variable_get('emfield_swfobject_location', ''))) {
// Use SWFObject API module if it's installed.
      // Note that we're going to try to send the Flv Media player as well,
      // assuming it's been set up and the flvmediaplayer module has not.
      $params['width'] = $width;
      $params['height'] = $height;
      $params['div_id'] = $id;
      $params['allowFullScreen'] = $fullscreen_value;
      $output = theme('emfield_swfobject', $url, $params, $flashvars, $id);
    }
    else if ($use_flv) {
      $flashvars = drupal_query_string_encode($flashvars);
      $output = <<<FLV
        <div id="$div_id"><embed src="$url" width="$width" height="$height" allowscriptaccess="always" allowfullscreen="$fullscreen_value" flashvars="$flashvars" /></div>
FLV;
    }
    else {
      switch ($type) {
          case 'swf':
          $output = '<embed src="'. $url .'" width="'. $width .'" height="'. $height .'" quality="high" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer"></embed>';
       }
    }
    return $output;
  
}

function emvideo_distant_flv_url_thumbnail($field, $item, $formatter, $node, $width, $height, $options = array()) {
  return '';
}

function emvideo_distant_flv_url_video($code, $width, $height, $field, $item, $node, $autoplay, $options = array()) {
  $type = $item['data']['type'];
  $options['node'] = $node;
  $output = theme('emvideo_distant_flv_url_embedded_video', $type, $code, $width, $height, $autoplay, $field, $item, $options);
  return $output;
}

function emvideo_distant_flv_url_preview($code, $width, $height, $field, $item, $node, $autoplay, $options = array()) {
  $type = $item['data']['type'];
  $options['node'] = $node;
  $output = theme('emvideo_distant_flv_url_embedded_video', $type, $code, $width, $height, $autoplay, $field, $item, $options);
  return $output;
}

/**
 * Implementation of hook_emfield_subtheme.
 */
function emvideo_distant_flv_url_emfield_subtheme() {
  return array(
    'emvideo_distant_flv_url_embedded_video' => array(
      'arguments' => array('type' => NULL, 'url' => NULL, 'width' => NULL, 'height' => NULL, 'autoplay' => FALSE, 'field' => NULL, 'item' => NULL),
      'file' => 'providers/distant_flv_url.inc',
      'path' => drupal_get_path('module', 'videocarousel'),
    )
  );
}
