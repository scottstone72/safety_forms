(function ($) {

  Drupal.behaviors.safety_forms_datepicker = {
    attach: function (context, settings) {

      // This is our jquery datepicker.
      $(".ui-datepicker", context).datepicker({
        beforeShow: function (input, inst) {
          setTimeout(function () {
            inst.dpDiv.css({
              'padding-top': 0,
              'margin-top': 0,
              'z-index': 20,
              'left': 800
              //'top': 200
            });
          }, 0);
        },
        dateFormat: "M d, yy",
        minDate: 0 // Setting minDate to zero restricts dates to only future dates.
      });


      // This is our jquery datepicker.
      $(".ui-datepicker-received", context).datepicker({
        beforeShow: function (input, inst) {
          setTimeout(function () {
            inst.dpDiv.css({
              'padding-top': 0,
              'margin-top': 0,
              'z-index': 20,
              'left': 70
              //'top': 200
            });
          }, 0);
        },
        dateFormat: "M d, yy",
        minDate: 0 // Setting minDate to zero restricts dates to only future dates.
      });

      // This is our jquery datepicker.
      $(".ui-datepicker-discussed", context).datepicker({
        beforeShow: function (input, inst) {
          setTimeout(function () {
            inst.dpDiv.css({
              'padding-top': 0,
              'margin-top': 0,
              'z-index': 20,
              'left': 340
              //'top': 200
            });
          }, 0);
        },
        dateFormat: "M d, yy",
        minDate: 0 // Setting minDate to zero restricts dates to only future dates.
      });

      // This is our jquery datepicker.
      $(".ui-datepicker-complete", context).datepicker({
        beforeShow: function (input, inst) {
          setTimeout(function () {
            inst.dpDiv.css({
              'padding-top': 0,
              'margin-top': 0,
              'z-index': 20,
              'left': 870
              //'top': 200
            });
          }, 0);
        },
        dateFormat: "M d, yy",
        minDate: 0 // Setting minDate to zero restricts dates to only future dates.
      });


      // This is our jquery datepicker.
      $(".ui-datepicker-follow", context).datepicker({
        beforeShow: function (input, inst) {
          setTimeout(function () {
            inst.dpDiv.css({
              'padding-top': 0,
              'margin-top': 0,
              'z-index': 20,
              'left': 620
              //'top': 200
            });
          }, 0);
        },
        dateFormat: "M d, yy",
        minDate: 0 // Setting minDate to zero restricts dates to only future dates.
      });


      // This is our jquery datepicker.
      $(".ui-datepicker-date-reviewed", context).datepicker({
        beforeShow: function (input, inst) {
          setTimeout(function () {
            inst.dpDiv.css({
              'padding-top': 0,
              'margin-top': 0,
              'z-index': 20,
              'left': 460
              //'top': 200
            });
          }, 0);
        },
        dateFormat: "M d, yy",
        minDate: 0 // Setting minDate to zero restricts dates to only future dates.
      });


      // This is our jquery datepicker.
      $(".ui-datepicker-valid-from", context).datepicker({
        beforeShow: function (input, inst) {
          setTimeout(function () {
            inst.dpDiv.css({
              'padding-top': 0,
              'margin-top': 0,
              'z-index': 20,
              'left': 90
              //'top': 200
            });
          }, 0);
        },
        dateFormat: "M d, yy",
        minDate: 0 // Setting minDate to zero restricts dates to only future dates.
      });


      // This is our jquery datepicker.
      $(".ui-datepicker-valid-to", context).datepicker({
        beforeShow: function (input, inst) {
          setTimeout(function () {
            inst.dpDiv.css({
              'padding-top': 0,
              'margin-top': 0,
              'z-index': 20,
              'left': 450
              //'top': 200
            });
          }, 0);
        },
        dateFormat: "M d, yy",
        minDate: 0 // Setting minDate to zero restricts dates to only future dates.
      });


      // This is our jquery datepicker.
      $(".ui-datepicker-renewed", context).datepicker({
        beforeShow: function (input, inst) {
          setTimeout(function () {
            inst.dpDiv.css({
              'padding-top': 0,
              'margin-top': 0,
              'z-index': 20,
              'left': 800
              //'top': 200
            });
          }, 0);
        },
        dateFormat: "M d, yy",
        minDate: 0 // Setting minDate to zero restricts dates to only future dates.
      });

    }
  };

})(jQuery);