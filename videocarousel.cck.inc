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
$content['groups']  = array (
  0 =>
  array (
    'label' => 'Local Video',
    'group_type' => 'standard',
    'settings' =>
    array (
      'form' =>
      array (
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' =>
      array (
        'description' => '',
        'teaser' =>
        array (
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' =>
        array (
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        4 =>
        array (
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '0',
    'group_name' => 'group_local_video',
  ),
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
      'f24_custom_url' => false,
      'google' => false,
      'guba' => false,
      'imeem' => false,
      'lastfm' => false,
      'livevideo' => false,
      'local_url' => false,
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
    ),
    'emthumb_store_local_thumbnail' => 1,
    'emthumb' => 1,
    'emthumb_label' => 'video custom thumbnail',
    'emthumb_description' => 'If you upload a custom thumbnail, then this will be displayed when the video thumbnail is called for, overriding any automatic thumbnails by custom providers.',
    'emthumb_max_resolution' => '0',
    'emimport_image_path' => '',
    'emthumb_custom_alt' => 0,
    'emthumb_custom_title' => 0,
    'emthumb_start_collapsed' => 0,
    'video_width' => '425',
    'video_height' => '363',
    'video_autoplay' => '',
    'preview_width' => '425',
    'preview_height' => '363',
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
        'emthumb' =>
        array (
          'emthumb' =>
          array (
            'emthumb' => '',
          ),
        ),
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'field_emvideo_0_file' => '',
    'upload' => 'Upload',
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
  1 =>
  array (
    'label' => 'Illustration',
    'field_name' => 'field_illustration',
    'type' => 'filefield',
    'widget_type' => 'imagefield_widget',
    'change' => 'Change basic information',
    'weight' => '-1',
    'file_extensions' => 'png gif jpg jpeg',
    'progress_indicator' => 'bar',
    'file_path' => '',
    'max_filesize_per_file' => '',
    'max_filesize_per_node' => '',
    'max_resolution' => 0,
    'min_resolution' => 0,
    'custom_alt' => 0,
    'alt' => '',
    'custom_title' => 0,
    'title_type' => 'textfield',
    'title' => '',
    'use_default_image' => 0,
    'default_image_upload' => '',
    'default_image' => NULL,
    'description' => '',
    'group' => 'group_local_video',
    'required' => 0,
    'multiple' => '0',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'op' => 'Save field settings',
    'module' => 'filefield',
    'widget_module' => 'imagefield',
    'columns' =>
    array (
      'fid' =>
      array (
        'type' => 'int',
        'not null' => false,
        'views' => true,
      ),
      'list' =>
      array (
        'type' => 'int',
        'size' => 'tiny',
        'not null' => false,
        'views' => true,
      ),
      'data' =>
      array (
        'type' => 'text',
        'serialize' => true,
        'views' => true,
      ),
    ),
    'display_settings' =>
    array (
      'weight' => '-1',
      'parent' => 'group_local_video',
      'label' =>
      array (
        'format' => 'above',
      ),
      'teaser' =>
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' =>
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      4 =>
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
  ),
  2 =>
  array (
    'label' => 'Local Video',
    'field_name' => 'field_local_video',
    'type' => 'filefield',
    'widget_type' => 'uploadfield_widget',
    'change' => 'Change basic information',
    'weight' => 0,
    'file_extensions' => 'mp4 mpeg avi mpg wmv flv',
    'progress_indicator' => 'bar',
    'file_path' => '',
    'max_filesize_per_file' => '',
    'max_filesize_per_node' => '',
    'default_resolution' => '16:9',
    'default_width' => '640',
    'default_video_thumb_upload' => '',
    'default_video_thumb' => NULL,
    'autoconversion' => 0,
    'autothumbnail' => 0,
    'description' => '',
    'group' => 'group_local_video',
    'required' => 0,
    'multiple' => '0',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'op' => 'Save field settings',
    'module' => 'filefield',
    'widget_module' => 'uploadfield',
    'columns' =>
    array (
      'fid' =>
      array (
        'type' => 'int',
        'not null' => false,
        'views' => true,
      ),
      'list' =>
      array (
        'type' => 'int',
        'size' => 'tiny',
        'not null' => false,
        'views' => true,
      ),
      'data' =>
      array (
        'type' => 'text',
        'serialize' => true,
        'views' => true,
      ),
    ),
    'display_settings' =>
    array (
      'weight' => 0,
      'parent' => 'group_local_video',
      'label' =>
      array (
        'format' => 'above',
      ),
      'teaser' =>
      array (
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      'full' =>
      array (
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      4 =>
      array (
        'format' => 'video_plain',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'body_field' => '-3',
  'revision_information' => '1',
  'comment_settings' => '2',
  'menu' => '-4',
);
