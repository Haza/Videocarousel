<?php

/**
 * @file
 *   This is an include file used by emfield.module.
 */

function _emvideo_local_url_default_types() {
  return array('flv');
}

function emvideo_local_url_info() {
  $name = t('Local URL');
  $features = array(
    array(t('Thumbnails'), t('No'), ''),
    array(t('Autoplay'), t('Yes'), ''),
    array(t('RSS attachment'), t('No'), ''),
  );
  return array(
    'provider' => 'local_url',
    'name' => $name,
    'url' => '',
    'settings_description' => t('These settings specifically affect videos displayed from custom URLs. When a field uses a URL it determines to be a link directly to a video file, it will embed that file into the content.'),
    'supported_features' => $features,
    'weight' => 9,
  );
}

function emvideo_local_url_settings() {
  $options = array(
    'flv' => t('Flash Video (flv)'),
  );
  $form = array();
  $form['emvideo_local_url_supported_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Supported Types'),
    '#options' => $options,
    '#default_value' => variable_get('emvideo_local_url_supported_types', _emvideo_local_url_default_types()),
    '#description' => t('Select the video types you wish to support. When a custom url with that type is entered into an embedded video field, it will be parsed and displayed appropriately. If a type is not supported, then it will be ignored.'),
  );
  return $form;
}

function _emvideo_local_url_implode_types() {
  return implode('|', variable_get('emvideo_local_url_supported_types', _emvideo_local_url_default_types()));
}

function emvideo_local_url_extract($embed = '') {
  $types = _emvideo_local_url_implode_types();
  $baseurl = preg_quote(url(null, array('absolute' => TRUE)), '@');

  return array(
    '@' . $baseurl . '(.*\.(?:' . $types . ')' . '(\?.*)?)@i',
    '@(.*\.(?:'. $types .')(\?.*)?)@i',
    '@'. $baseurl.'(.*(?:xspf))@i',
    '@(.*(?:xspf))@i',
  );
}

function emvideo_local_url_data($field, $item) {
  $data = array();
  // adding the version control
  $data['emvideo_local_url_data_version'] = 1;

  // attempt to get info from headers
  $response = emfield_request_header('local_url', $item['embed']);

  if ($response->code == 200) {
    $data['url'] = $item['embed'];
    $data['size'] = $response->headers['Content-Length'];
    $data['mime'] = $response->headers['Content-Type'];
  }
  // @todo replace ['type'] with converted mime info if available
  $types = _emvideo_local_url_implode_types();
  $regex = '@\.('. $types .')$@i';
  if (preg_match($regex, $item['embed'], $matches)) {
    $data['type'] = $matches[1];
  }
  return $data;
}

/**
 * hook emfield_PROVIDER_rss
 */
function emvideo_local_url_rss($item, $teaser = NULL) {
  if ($item['value']) {
    if ($item['data']['emvideo_local_url_data_version'] >= 1) {
      $data = $item['data'];
    }
    else {
      $data = emvideo_local_url_data(NULL, $item);
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


function emvideo_local_url_embedded_link($video_code) {
  return $video_code;
}

function theme_emvideo_local_url_embedded_video($type, $url, $width, $height, $autoplay = FALSE, $field = NULL, $item = NULL, $options = array()) {

    $height = 470;
    $width = 383;
     // If the JW FLV Player has been installed, the yt.swf file is in the same
    // folder, and the server has been configured to use it for YouTube videos,
    // then we'll do so now.
    $use_flv = isset($options['use_flv']) ? $options['use_flv'] : variable_get('emvideo_zzz_custom_url_use_jw_flv', TRUE);

    // Set up the FLV Media Player options, assuming we're supposed to,
    // and the player is actually installed on the system.
    if ($use_flv && ($flv_path = emfield_flvmediaplayer_url())) {
      global $base_path;

      // Build the Thumbnail image for the player.
      $tn_options = array(
        'width' => $width,
        'height' => $height,
        'return_url' => TRUE,
      );

      $flashvars = array();

      // Grab the thumbnail for this video and tell JW FLV Player about it.
      $flashvars['image'] = theme('emvideo_video_thumbnail', NULL, $item, 'emvideo_thumbnail', $options['node'], FALSE, $tn_options);

      // We need to set the file to the original video.
      $flashvars['file'] = $url;

      // The JW FLV Player uses its own autoplay flashvar.
      $flashvars['autostart'] = $autoplay ? 'true' : 'false';

      // The URL will now be the JW FLV Player.
      $url = $base_path . $flv_path;
    }
    return $output;
  
}

function emvideo_local_url_thumbnail($field, $item, $formatter, $node, $width, $height, $options = array()) {
  return '';
}

function emvideo_local_url_video($code, $width, $height, $field, $item, $node, $autoplay, $options = array()) {
  $type = $item['data']['type'];
  $options['node'] = $node;
  $output = theme('emvideo_local_url_embedded_video', $type, $code, $width, $height, $autoplay, $field, $item, $options);
  return $output;
}

function emvideo_local_url_preview($code, $width, $height, $field, $item, $node, $autoplay, $options = array()) {
  $type = $item['data']['type'];
  $options['node'] = $node;
  $output = theme('emvideo_local_url_embedded_video', $type, $code, $width, $height, $autoplay, $field, $item, $options);
  return $output;
}

/**
 * Implementation of hook_emfield_subtheme.
 */
function emvideo_local_url_emfield_subtheme() {
  return array(
    'emvideo_local_url_embedded_video' => array(
      'arguments' => array('type' => NULL, 'url' => NULL, 'width' => NULL, 'height' => NULL, 'autoplay' => FALSE, 'field' => NULL, 'item' => NULL),
      'file' => 'providers/local_url.inc',
      'path' => drupal_get_path('module', 'videocarousel'),
    )
  );
}
