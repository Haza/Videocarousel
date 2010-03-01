Drupal.behaviors.videocarousel = function (context) {
  $(".videocarousel-item").click(function () {
    $(".videocarousel-video-container").hide();
    $(".videocarousel-item-body").hide();
    $(".videocarousel-item-title").hide();
    $("#"+this.id + "-main").show();
    $("#"+this.id + "-title").show();
    $("#"+this.id + "-body").show();
  });
}; 