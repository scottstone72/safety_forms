<?php
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/erp_drills_meeting_form.min.css');

/*
 * ERP Drills Meeting Form
 * Implements hook_form()
 */
function erp_drills_meeting_form($form, &$form_state) {

  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('ERP Drills Meeting'),
  );

  $form['main_container']['message'] = array(
    '#markup' => '<div class="user-message">Drills are regularly held to ensure everyone has a clear understanding of what to do in the
                    event of an emergency. Drills can either be a discussion where the event is reviewed
                    or an actual role play where takes part in the drill.</div>',
  );

  $form['main_container']['form_body'] = array(
    '#type' => 'fieldset',
  );

  // Start form elements
  $form['main_container']['form_body']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date'),
    '#default_value' => date('M d, Y'),
    '#disabled' => TRUE,
    '#prefix' => '<div class="date">',
    '#suffix' => '</div>',
  );

  $form['main_container']['form_body']['recorded_by'] = array(
    '#type' => 'textfield',
    '#title' => t('Recorded By'),
    '#default_value' => '',
    '#prefix' => '<div class="recorded-by">',
    '#suffix' => '</div>'
  );

  $form['main_container']['form_body']['box'] = array(
    '#type' => 'fieldset',
    '#title' => t('Choose Drill'),
    '#attributes' => array('class' => array('box')),
  );

  $form['main_container']['form_body']['box']['drill_type'] = array(
    '#type' => 'radios',
    '#title' => t(''),
    '#options' => array(
      'bop_drill' => 'BOP Drill',
      'man_down' => 'Man Down',
      'confined_space' => 'Confined Space',
      'h2s' => 'H2S',
      'fire' => 'Fire',
      'evacuation' => 'Evacuation',
      'high_angle_rescue' => 'High Angle Rescue',
      'natural_disaster' => 'Natural Disaster',
    ),
  );

  $form['main_container']['form_body']['attendance'] = array(
    '#type' => 'textarea',
    '#title' => t('Attendance (sign name) (each name on new line)'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="attendance">',
    '#suffix' => '</div>'
  );


  $form['main_container']['form_body']['summary_of_drills'] = array(
    '#type' => 'textarea',
    '#title' => t('Summary Of Drill(s) performed'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="summary-of-drills">',
    '#suffix' => '</div>',
  );

  $form['main_container']['form_body']['hazard_review'] = array(
    '#type' => 'textarea',
    '#title' => t('Hazard Review'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="hazard-review">',
    '#suffix' => '</div>',
  );


  $form['main_container']['form_body']['other'] = array(
    '#type' => 'textarea',
    '#title' => t('Other'),
    '#default_value' => '',
    '#prefix' => '<div class="other">',
    '#suffix' => '</div>',
  );


  $form['main_container']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit ERP Drill Meeting Form',
    '#executes_submit_callback' => TRUE,
  );


  return $form;
}

function erp_drills_meeting_form_validate($form, &$form_state) {

  $data = array(
    'attendance' => $form_state['values']['attendance'],
    'summary_of_drills' => $form_state['values']['summary_of_drills'],
    'hazard_review' => $form_state['values']['hazard_review'],
    'other' => $form_state['values']['other'],
  );

  $form_state['erp_data'] = serialize($data);
}

function erp_drills_meeting_form_submit($form, &$form_state) {

  $fields = array(
        'date' => $form_state['values']['date'],
        'recorded_by' => $form_state['values']['recorded_by'],
        'drill_type' => $form_state['values']['drill_type'],
        'erp_form_data' => $form_state['erp_data'],
        'timestamp' => time(),
  );

  $query = db_insert('erp_drills_meeting_form')
    ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';
}
