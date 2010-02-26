<?php
/**
 * @file
 *  Provides the views plugin information.
 */

/**
  * Implementation of hook_views_plugin().
  */
function videocarousel_views_plugins() {
  return array(
    'module' => 'videocarousel',
    'style' => array(
      'videocarousel' => array(
        'title' => t('videocarousel Carousel'),
        'theme' => 'videocarousel_view',
        'help' => t('Display rows in a Carousel via jCarousel.'),
        'handler' => 'videocarousel_style_plugin',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
