(function ($) {

  Drupal.behaviors.repair_approval_datepicker = {
    attach: function (context, settings) {

      // This is our jquery datepicker.
      $(".ui-datepicker", context).datepicker({
        beforeShow: function (input, inst) {
          setTimeout(function () {
            inst.dpDiv.css({
              //'padding-top': 0,
              //'margin-top': 0,
              //'z-index': 20,
              //'left': 100
              //'top': 200
            });
          }, 0);
        },
        dateFormat: "M d, Y",
        minDate: 0 // Setting minDate to zero restricts dates to only future dates.
      });
    }
  };

})(jQuery);