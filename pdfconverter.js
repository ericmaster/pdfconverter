( function($) {
  Drupal.behaviors.pdfconverter = {
    attach : function(context, settings) {
      
      if($('#edit-instance-settings-pdfconverter').attr('checked')){
        $('#edit-instance-settings-file-extensions').attr('disabled', 'disabled');
      }
      
      $('#edit-instance-settings-pdfconverter:not(.pdfconverter-processed)').addClass('pdfconverter-processed').change(function(){
        if($(this).attr('checked')){
          $('#edit-instance-settings-file-extensions').val('pdf');
          $('#edit-instance-settings-file-extensions').attr('disabled', 'disabled');
        }else{
          $('#edit-instance-settings-file-extensions').removeAttr('disabled');
        }
      });
    }
  }
}(jQuery))