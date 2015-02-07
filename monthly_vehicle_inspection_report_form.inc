<?php

drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/monthly_vehicle_inspection_report_form.min.css');


/**
 * Monthly Vehicle Inspection Report Form
 */
function monthly_vehicle_inspection_report_form($form, &$form_state) {

  // Array to help build our (similar) form elements
  $ele_arr = array(
    'engine_oil' => t('Engine Oil'),
    'coolant_level' => t('Coolant Level'),
    'trans_fluid_level' => t('Transmission Fluid Level'),
    'seat_belts' => t('Seat Belts'),
    'battery' => t('Battery'),
    'tires' => t('Tires'),
    'fan_belts' => t('Fan Belts'),
    'headlights' => t('Headlights'),
    'tail_lights' => t('Tail Lights'),
    'brake_lights' => t('Brake Lights'),
    'turn_signals' => t('Turn Signals'),
    'all_glass_and_mirrors' => t('All Glass and Mirrors'),
    'body_damage' => t('Body Damage'),
    'overall_vehicle_cleanliness' => t('Overall Vehicle Cleanliness'),
    'hoses' => t('Hoses'),
    'gauges' => t('Gauges'),
    'vehicle_accident_kit' => t('Vehicle Accident Kit'),
    'fire_extinguisher' => t('Fire Extinguisher'),
    'parking_brake' => t('Parking Brake'),
    'horn' => t('Horn'),
    'steering_wheel_play' => t('Steering Wheel Play'),
    'first_aid_kit' => t('First Aid Kit'),
    'brakes' => t('Brakes'),
  );

  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Monthly Vehicle Inspection Report Form'),
  );

  $form['main_container']['make'] = array(
    '#type' => 'textfield',
    '#title' => t('Make'),
    '#description' => 'Make of vehicle.',
    '#default_value' => '',
    '#prefix' => '<div class="vehicle-make">',
    '#suffix' => '</div>',
//    '#required' => TRUE,
  );

  $form['main_container']['license_plate_num'] = array(
    '#type' => 'textfield',
    '#title' => t('License Plate Number'),
    '#description' => 'License Plate Number on vehicle.',
    '#default_value' => '',
    '#prefix' => '<div class="license-plate-num">',
    '#suffix' => '</div>',
    //    '#required' => TRUE,
  );

  $form['main_container']['model'] = array(
    '#type' => 'textfield',
    '#title' => t('Model'),
    '#description' => 'Model of vehicle.',
    '#default_value' => '',
    '#prefix' => '<div class="vehicle-model">',
    '#suffix' => '</div>',
    //    '#required' => TRUE,
  );

  $form['main_container']['mileage'] = array(
    '#type' => 'textfield',
    '#title' => t('Mileage'),
    '#description' => 'Mileage on vehicle.',
    '#default_value' => '',
    '#prefix' => '<div class="vehicle-mileage">',
    '#suffix' => '</div>',
    //    '#required' => TRUE,
  );

  $form['main_container']['assigned_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Assigned To'),
    '#description' => 'Person assigned to this vehicle.',
    '#default_value' => '',
    '#prefix' => '<div class="vehicle-assigned-to">',
    '#suffix' => '</div>',
    //    '#required' => TRUE,
  );

  $form['main_container']['vehicle_data'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#prefix' => '<div class="cont-container">',
    '#suffix' => '</div>',
  );


  // Build our elements that are all similar except the tires element
  foreach($ele_arr as $key => $val) {

    $form['main_container']['vehicle_data'][$key] = array(
      '#type' => 'fieldset',
      '#title' => $val,
      '#prefix' => '<div class="cont-title">',
      '#suffix' => '</div>',
    );

    $form['main_container']['vehicle_data'][$key][$key . '_radio'] = array(
      '#type' => 'radios',
      '#title' => t(''),
      '#options' => array(
        'satisfactory' => t('Satisfactory'),
        'replace' => t('Replace'),
        'na' => t('Not Applicable'),
      ),
      '#description' => '',
      '#prefix' => '<div class="cont-radio">',
      '#suffix' => '</div>',
      //    '#required' => TRUE,
    );

    $form['main_container']['vehicle_data'][$key][$key . '_comm'] = array(
      '#type' => 'textfield',
      '#title' => t('Comments'),
//      '#title_display' => 'invisible',
      '#default_value' => $key === 'tires' ? 'FL:          FR:          RL:          RR:' : '',
      '#prefix' => '<div class="cont-comm">',
      '#suffix' => '</div>',
      //    '#required' => TRUE,
    );
  }

  $form['main_container']['remarks'] = array(
    '#type' => 'textarea',
    '#title' => t('Remarks'),
    '#description' => 'Any remarks about the vehicle.',
    '#default_value' => '',
    '#prefix' => '<div class="remarks">',
    '#suffix' => '</div>',
    //    '#required' => TRUE,
  );

  $form['main_container']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date'),
    '#default_value' => date('M d, Y'),
    '#prefix' => '<div class="date">',
    '#suffix' => '</div>',
    //    '#required' => TRUE,
  );

  $form['main_container']['managers_sign'] = array(
    '#type' => 'textfield',
    '#title' => t('Manager\'s Signature'),
    '#default_value' => '',
    '#prefix' => '<div class="managers-sign">',
    '#suffix' => '</div>',
    //    '#required' => TRUE,
  );

  $form['main_container']['drivers_sign'] = array(
    '#type' => 'textfield',
    '#title' => t('Drivers Signature'),
    '#default_value' => '',
    '#prefix' => '<div class="drivers-sign">',
    '#suffix' => '</div>',
    //    '#required' => TRUE,
  );

//  $form['main_container']['drivers_date'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Date'),
//    '#default_value' => '',
//    '#prefix' => '<div class="drivers-date">',
//    '#suffix' => '</div>',
//    //    '#required' => TRUE,
//  );

  $form['main_container']['submit_button'] = array(
    '#type' => 'submit',
    '#value' => 'Submit Monthly Vehicle Inspection Report Form',
    '#prefix' => '<div class="submit-button">',
    '#suffix' => '</div>',
  );


  return $form;
}

/**
 * Validate monthly_vehicle_inspection_report_form
 */
function monthly_vehicle_inspection_report_form_validate($form, &$form_state) {
  // Clean out default form_state values
  form_state_values_clean($form_state);
}

/**
 * Submit monthly_vehicle_inspection_report_form
 */
function monthly_vehicle_inspection_report_form_submit($form, &$form_state) {

  $fields = array(
    'make' => $form_state['values']['make'],
    'license_plate_num' => $form_state['values']['license_plate_num'],
    'model' => $form_state['values']['model'],
    'mileage' => $form_state['values']['mileage'],
    'assigned_to' => $form_state['values']['assigned_to'],
    'vehicle_data' => serialize($form_state['values']['vehicle_data']),
    'remarks' => $form_state['values']['remarks'],
    'date' => $form_state['values']['date'],
    'managers_sign' => $form_state['values']['managers_sign'],
    'drivers_sign' => $form_state['values']['drivers_sign'],
    'timestamp' => time(),
  );

  $query = db_insert('monthly_vehicle_inspection_report_form')
    ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';

}