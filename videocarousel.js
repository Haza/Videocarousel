Drupal.behaviors.videocarousel = function (context) {
  $("#videocarousel-item-1").css("opacity", "0.5")
  $(".videocarousel-item").click(function () {
    $(".videocarousel-item").css("opacity", "1")
    $(".videocarousel-video-container").hide();
    $(".videocarousel-item-body").hide();
    $(".videocarousel-item-title").hide();
    $("#"+this.id + "-main").show();
    $("#"+this.id + "-title").show();
    $("#"+this.id + "-body").show();
    $("#"+this.id).css("opacity","0.5");
  });
}; 