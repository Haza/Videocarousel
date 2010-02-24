<?php
/**
 * @file
 *  Provides the views plugin information.
 */

/**
  * Implementation of hook_views_plugin().
  */
function moutarde_views_plugins() {
  return array(
    'module' => 'moutarde',
    'style' => array(
      'moutarde' => array(
        'title' => t('Moutarde Carousel'),
        'theme' => 'moutarde_view',
        'help' => t('Display rows in a Carousel via jCarousel.'),
        'handler' => 'moutarde_style_plugin',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}