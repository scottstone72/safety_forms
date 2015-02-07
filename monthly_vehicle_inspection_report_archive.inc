<?php

require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/monthly_vehicle_inspection_report_form.min.css');


/**
 * Monthly Vehicle Inspection Report Form
 */
function monthly_vehicle_inspection_report_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);
//  $ele_arr = array();

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('monthly_vehicle_inspection_report_form',  $id, $month = NULL, $year = NULL, $permit_num = NULL, $jsa = NULL);

  foreach($safety_data as $key => $val) {

    $data = unserialize($val['vehicle_data']);

    // Array to help build our (similar) form elements
    $ele_arr = array(
      'engine_oil' => array(t('Engine Oil'), $data['engine_oil']['engine_oil_radio'], $data['engine_oil']['engine_oil_comm']),
      'coolant_level' => array(t('Coolant Level'), $data['coolant_level']['coolant_level_radio'], $data['coolant_level']['coolant_level_comm']),
      'trans_fluid_level' => array(t('Transmission Fluid Level'), $data['trans_fluid_level']['trans_fluid_level_radio'], $data['trans_fluid_level']['trans_fluid_level_comm']),
      'seat_belts' => array(t('Seat Belts'), $data['seat_belts']['seat_belts_radio'], $data['seat_belts']['seat_belts_comm']),
      'battery' => array(t('Battery'), $data['battery']['battery_radio'], $data['battery']['battery_comm']),
      'tires' => array(t('Tires'), $data['tires']['tires_radio'], $data['tires']['tires_comm']),
      'fan_belts' => array(t('Fan Belts'), $data['fan_belts']['fan_belts_radio'], $data['fan_belts']['fan_belts_comm']),
      'headlights' => array(t('Headlights'), $data['headlights']['headlights_radio'], $data['headlights']['headlights_comm']),
      'tail_lights' => array(t('Tail Lights'), $data['tail_lights']['tail_lights_radio'], $data['tail_lights']['tail_lights_comm']),
      'brake_lights' => array(t('Brake Lights'), $data['brake_lights']['brake_lights_radio'], $data['brake_lights']['brake_lights_comm']),
      'turn_signals' => array(t('Turn Signals'), $data['turn_signals']['turn_signals_radio'], $data['turn_signals']['turn_signals_comm']),
      'all_glass_and_mirrors' => array(t('All Glass and Mirrors'), $data['all_glass_and_mirrors']['all_glass_and_mirrors_radio'], $data['all_glass_and_mirrors']['all_glass_and_mirrors_comm']),
      'body_damage' => array(t('Body Damage'), $data['body_damage']['body_damage_radio'], $data['body_damage']['body_damage_comm']),
      'overall_vehicle_cleanliness' => array(t('Overall Vehicle Cleanliness'), $data['overall_vehicle_cleanliness']['overall_vehicle_cleanliness_radio'], $data['overall_vehicle_cleanliness']['overall_vehicle_cleanliness_comm']),
      'hoses' => array(t('Hoses'), $data['hoses']['hoses_radio'], $data['hoses']['hoses_comm']),
      'gauges' => array(t('Gauges'), $data['gauges']['gauges_radio'], $data['gauges']['gauges_comm']),
      'vehicle_accident_kit' => array(t('Vehicle Accident Kit'), $data['vehicle_accident_kit']['vehicle_accident_kit_radio'], $data['vehicle_accident_kit']['vehicle_accident_kit_comm']),
      'fire_extinguisher' => array(t('Fire Extinguisher'), $data['fire_extinguisher']['fire_extinguisher_radio'], $data['fire_extinguisher']['fire_extinguisher_comm']),
      'parking_brake' => array(t('Parking Brake'), $data['parking_brake']['parking_brake_radio'], $data['parking_brake']['parking_brake_comm']),
      'horn' => array(t('Horn'), $data['horn']['horn_radio'], $data['horn']['horn_comm']),
      'steering_wheel_play' => array(t('Steering Wheel Play'), $data['steering_wheel_play']['steering_wheel_play_radio'], $data['steering_wheel_play']['steering_wheel_play_comm']),
      'first_aid_kit' => array(t('First Aid Kit'), $data['first_aid_kit']['first_aid_kit_radio'], $data['first_aid_kit']['first_aid_kit_comm']),
      'brakes' => array(t('Brakes'), $data['brakes']['brakes_radio'], $data['brakes']['brakes_comm']),
    );


    $form['main_container'] = array(
      '#type' => 'fieldset',
      '#title' => t('Monthly Vehicle Inspection Report Form # '. $id),
    );

    $form['main_container']['make'] = array(
      '#type' => 'textfield',
      '#title' => t('Make'),
//      '#description' => 'Make of vehicle.',
      '#default_value' => $val['make'],
      '#prefix' => '<div class="vehicle-make">',
      '#suffix' => '</div>',
      '#disabled' => TRUE,
    );

    $form['main_container']['license_plate_num'] = array(
      '#type' => 'textfield',
      '#title' => t('License Plate Number'),
//      '#description' => 'License Plate Number on vehicle.',
      '#default_value' => $val['license_plate_num'],
      '#prefix' => '<div class="license-plate-num">',
      '#suffix' => '</div>',
      '#disabled' => TRUE,
    );

    $form['main_container']['model'] = array(
      '#type' => 'textfield',
      '#title' => t('Model'),
//      '#description' => 'Model of vehicle.',
      '#default_value' => $val['model'],
      '#prefix' => '<div class="vehicle-model">',
      '#suffix' => '</div>',
      '#disabled' => TRUE,
    );

    $form['main_container']['mileage'] = array(
      '#type' => 'textfield',
      '#title' => t('Mileage'),
//      '#description' => 'Mileage on vehicle.',
      '#default_value' => $val['mileage'],
      '#prefix' => '<div class="vehicle-mileage">',
      '#suffix' => '</div>',
      '#disabled' => TRUE,
    );

    $form['main_container']['assigned_to'] = array(
      '#type' => 'textfield',
      '#title' => t('Assigned To'),
//      '#description' => 'Person assigned to this vehicle.',
      '#default_value' => $val['assigned_to'],
      '#prefix' => '<div class="vehicle-assigned-to">',
      '#suffix' => '</div>',
      '#disabled' => TRUE,
    );

    $form['main_container']['vehicle_data'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#prefix' => '<div class="cont-container">',
      '#suffix' => '</div>',
    );

    // Build our elements that are all similar except the tires element
    foreach ($ele_arr as $k => $v) {

        $form['main_container']['vehicle_data'][$k] = array(
          '#type' => 'fieldset',
          '#title' => $v[0],
          '#prefix' => '<div class="cont-title">',
          '#suffix' => '</div>',
        );

        $form['main_container']['vehicle_data'][$k][$k . '_radio'] = array(
          '#type' => 'radios',
          '#title' => t(''),
          '#options' => array(
            'satisfactory' => t('Satisfactory'),
            'replace' => t('Replace'),
            'na' => t('Not Applicable'),
          ),
          '#default_value' => $v[1],
          '#prefix' => '<div class="cont-radio">',
          '#suffix' => '</div>',
          '#disabled' => TRUE,
        );

        $form['main_container']['vehicle_data'][$k][$k . '_comm'] = array(
          '#type' => 'textfield',
          '#title' => t('Comments'),
          //      '#title_display' => 'invisible',
          '#default_value' => $v[2],
          '#prefix' => '<div class="cont-comm">',
          '#suffix' => '</div>',
          '#disabled' => TRUE,
        );
    }

    $form['main_container']['remarks'] = array(
      '#type' => 'textarea',
      '#title' => t('Remarks'),
      '#description' => 'Any remarks about the vehicle.',
      '#default_value' => $val['remarks'],
      '#prefix' => '<div class="remarks">',
      '#suffix' => '</div>',
      '#disabled' => TRUE,
    );

    $form['main_container']['date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date'),
      '#default_value' => $val['date'],
      '#prefix' => '<div class="date">',
      '#suffix' => '</div>',
      '#disabled' => TRUE,
    );

    $form['main_container']['managers_sign'] = array(
      '#type' => 'textfield',
      '#title' => t('Manager\'s Signature'),
      '#default_value' => $val['managers_sign'],
      '#prefix' => '<div class="managers-sign">',
      '#suffix' => '</div>',
      '#disabled' => TRUE,
    );

    $form['main_container']['drivers_sign'] = array(
      '#type' => 'textfield',
      '#title' => t('Drivers Signature'),
      '#default_value' => $val['drivers_sign'],
      '#prefix' => '<div class="drivers-sign">',
      '#suffix' => '</div>',
      '#disabled' => TRUE,
    );
  }

  return $form;
}
