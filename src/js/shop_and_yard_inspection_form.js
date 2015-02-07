(function($) {

  Drupal.behaviors.shop_and_yard = {
    attach: function (context, settings) {

      $('.action-cont .form-textarea').each(function(key,value) {

        var comments = $(value).val();

        if (!comments) {
          var id = $(value).attr('id');
          // Close any field that doesn't have a value
          $('#' + id).parents('div.action-cont').once().hide(); // Hide the forms on page load.
        }
      });


      //$('.action-cont').once().hide(); // Hide the forms on page load.

      // Toggle fieldsets when user clicks show Details or the Cancel button
      $(".add-comments", context).click(function () {

        table_num = $(this).attr('value');
        console.log(table_num);
        selFieldset = '#collapse_'+ table_num;

        var selectdiv = $(selFieldset);
        selectdiv.slideToggle(300);
        //var elem = selectdiv.slideToggle(800);
        //$('.approval-fieldset').not(elem).hide();
      }); // End click event


    }
  };

})(jQuery);