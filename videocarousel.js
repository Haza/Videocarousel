Drupal.behaviors.videocarousel = function (context) {
  $(".videocarousel-item").click(function () {
    $(".videocarousel-video-container").hide();
    $("#"+this.id + "-main").show();
  });
}; 