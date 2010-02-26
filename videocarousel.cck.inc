$content['type']  = array (
  'name' => 'Video Carousel',
  'type' => 'videocarousel',
  'description' => '',
  'title_label' => 'Title',
  'body_label' => 'Body',
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array (
    'status' => true,
    'promote' => true,
    'sticky' => false,
    'revision' => false,
  ),
  'old_type' => 'videocarousel',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'comment' => '2',
  'comment_default_mode' => '4',
  'comment_default_order' => '1',
  'comment_default_per_page' => '50',
  'comment_controls' => '3',
  'comment_anonymous' => 0,
  'comment_subject_field' => '1',
  'comment_preview' => '1',
  'comment_form_location' => '0',
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'video',
    'field_name' => 'field_emvideo',
    'type' => 'emvideo',
    'widget_type' => 'emvideo_textfields',
    'change' => 'Change basic information',
    'weight' => '-2',
    'providers' => 
    array (
      0 => 1,
      'archive' => false,
      'bliptv' => false,
      'dailymotion' => false,
      'google' => false,
      'guba' => false,
      'imeem' => false,
      'lastfm' => false,
      'livevideo' => false,
      'metacafe' => false,
      'myspace' => false,
      'revver' => false,
      'sevenload' => false,
      'spike' => false,
      'tudou' => false,
      'twistage' => false,
      'ustream' => false,
      'ustreamlive' => false,
      'vimeo' => false,
      'voicethread' => false,
      'yahoomusic' => false,
      'youtube' => false,
      'zzz_custom_url' => false,
    ),
    'emthumb_store_local_thumbnail' => 1,
    'emthumb' => 0,
    'emthumb_label' => 'video custom thumbnail',
    'emthumb_description' => 'If you upload a custom thumbnail, then this will be displayed when the video thumbnail is called for, overriding any automatic thumbnails by custom providers.',
    'emthumb_max_resolution' => '0',
    'emimport_image_path' => '',
    'emthumb_custom_alt' => 0,
    'emthumb_custom_title' => 0,
    'emthumb_start_collapsed' => 0,
    'video_width' => '425',
    'video_height' => '350',
    'video_autoplay' => '',
    'preview_width' => '425',
    'preview_height' => '350',
    'preview_autoplay' => '',
    'thumbnail_width' => '120',
    'thumbnail_height' => '90',
    'thumbnail_default_path' => '',
    'thumbnail_link_title' => 'See video',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'embed' => '',
        'value' => '',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'op' => 'Save field settings',
    'module' => 'emvideo',
    'widget_module' => 'emvideo',
    'columns' => 
    array (
      'embed' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
      ),
      'value' => 
      array (
        'type' => 'varchar',
        'length' => 255,
        'not null' => false,
        'sortable' => true,
      ),
      'provider' => 
      array (
        'type' => 'varchar',
        'length' => 255,
        'not null' => false,
        'sortable' => true,
      ),
      'data' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => false,
      ),
      'version' => 
      array (
        'description' => 'The version of the provider\'s data.',
        'type' => 'int',
        'unsigned' => true,
        'not null' => true,
        'default' => 0,
      ),
      'duration' => 
      array (
        'description' => 'Store the duration of a video in seconds.',
        'type' => 'int',
        'unsigned' => true,
        'not null' => true,
        'default' => 0,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'body_field' => '-3',
  'revision_information' => '-1',
  'comment_settings' => '0',
  'menu' => '-4',
);

