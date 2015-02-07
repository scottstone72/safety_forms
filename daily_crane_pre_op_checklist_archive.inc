<?php

require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/daily_crane_pre_op_checklist_form.min.css');

/**
 * Daily Crane Inspection Report
 */
function daily_crane_pre_op_checklist_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('daily_crane_pre_op_checklist_form', $id, $month = NULL, $year = NULL, $permit_num = NULL, $jsa = NULL);

  foreach ($safety_data as $key => $val) {
    // Unserialize our data array
    $data = unserialize($val['crane_data']);

    $form['main_container'] = array(
      '#type' => 'fieldset',
      '#title' => t('Daily Crane Pre-Operation Checklist Form'),
    );

    $form['main_container']['inspected_by'] = array(
      '#type' => 'textfield',
      '#title' => t('Inspected By'),
      '#description' => t('Person doing inspection.'),
      '#default_value' => $val['inspected_by'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="top">',
      '#suffix' => '</div>',
    );

    $form['main_container']['date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date'),
      '#default_value' => $val['date'],
      '#prefix' => '<div class="top">',
      '#suffix' => '</div>',
    );

    $form['main_container']['signature'] = array(
      '#type' => 'textfield',
      '#title' => t('Signature'),
      '#description' => t('Signature'),
      '#default_value' => $val['signature'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="top">',
      '#suffix' => '</div>',
    );

    $form['main_container']['one'] = array( // Description container
                                            '#type' => 'fieldset',
    );

    $form['main_container']['one']['1'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">1.</strong>&nbsp&nbspCheck the hoists upper limit: raise hook block without load,
        stop at approximately 2 feet from the bottom side of the hoist,
        then raise the block in slow speed. If the block does not
        stop where it should, stop and have the limits checked
        (mechanically or electrically), be careful not to allow the
        block to get into the underside of the hoist and cause
        entanglement.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['one']['ok_1'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_1'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['one']['repair_1'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 1'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_1'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['two'] = array(
      '#type' => 'fieldset',
    );

    $form['main_container']['two']['2'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">2.</strong>&nbsp&nbspLower hook block to the lowest point without setting the
        block on the floor. If equipped, the lower limit should stop
        hook from hitting the floor.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['two']['ok_2'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_2'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['two']['repair_2'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 2'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_2'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['three'] = array( // Description container
                                              '#type' => 'fieldset',
    );

    $form['main_container']['three']['3'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">3.</strong>&nbsp&nbspWhile the block is lowered, the operator should inspect each
      wire rope line looking for kinks, frays, bird cage, broken
      wires, heat damage, welding spatter and is properly
      lubricated. If any of this is noted, the hoist must not be used.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['three']['ok_3'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_3'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['three']['repair_3'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 3'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_3'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['four'] = array( // Description container
                                             '#type' => 'fieldset',
    );

    $form['main_container']['four']['4'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">4.</strong>&nbsp&nbspCheck the functionality of all switches/buttons on the
      control box to see if the hoist moves or stops promptly.
      test the stop button and verify the proper brake distances.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['four']['ok_4'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_4'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['four']['repair_4'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 4'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_4'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['five'] = array( // Description container
                                             '#type' => 'fieldset',
    );

    $form['main_container']['five']['5'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">5.</strong>&nbsp&nbspRun all motions and check for abnormal noises.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['five']['ok_5'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_5'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['five']['repair_5'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 5'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_5'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['six'] = array( // Description container
                                            '#type' => 'fieldset',
    );

    $form['main_container']['six']['6'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">6.</strong>&nbsp&nbspCheck that the bottom hook rotates freely.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['six']['ok_6'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_6'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['six']['repair_6'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 6'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_6'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['seven'] = array( // Description container
                                              '#type' => 'fieldset',
    );

    $form['main_container']['seven']['7'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">7.</strong>&nbsp&nbspCheck that the safety latch is securely fastened to hook
        and is functioning normally.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['seven']['ok_7'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_7'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['seven']['repair_7'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 7'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_7'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['eight'] = array(
      '#type' => 'fieldset',
    );

    $form['main_container']['eight']['8'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">8.</strong>&nbsp&nbspCheck that there is no wear between the chain links.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['eight']['ok_8'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_8'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['eight']['repair_8'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 8'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_8'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['nine'] = array(
     '#type' => 'fieldset',
    );

    $form['main_container']['nine']['9'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">9.</strong>&nbsp&nbspCheck for proper functions for wrapping cable and the
        trolley.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['nine']['ok_9'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_9'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['nine']['repair_9'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 9'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_9'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['ten'] = array( // Description container
                                            '#type' => 'fieldset',
    );

    $form['main_container']['ten']['10'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">10.</strong>&nbsp&nbspCheck: operating controls should be auto-return and should
      return to a neutral position when the control is released.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['ten']['ok_10'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_10'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['ten']['repair_10'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 10'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_10'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['eleven'] = array(
      '#type' => 'fieldset',
    );

    $form['main_container']['eleven']['11'] = array(
      '#type' => 'markup',
      '#markup' => '<div><strong class="num">11.</strong>&nbsp&nbspCheck that the wire rope is seated properly in the drum
      grooves.</div>',
      '#prefix' => '<div class="desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['eleven']['ok_11'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ok'),
      '#default_value' => $data['ok_11'],
      '#prefix' => '<div class="ok">',
      '#suffix' => '</div>',
    );

    $form['main_container']['eleven']['repair_11'] = array(
      '#type' => 'textarea',
      '#title' => t('Repair 11'),
      '#rows' => 3,
      '#description' => t('Description of repairs needed.'),
      '#default_value' => $data['repair_11'],
      '#prefix' => '<div class="repair">',
      '#suffix' => '</div>',
    );

    $form['main_container']['comments'] = array(
      '#type' => 'textarea',
      '#title' => t('Comments'),
      '#default_value' => $data['comments'],
      '#prefix' => '<div class="comments">',
      '#suffix' => '</div>',
    );
  }


  $form['main_container']['link_to_safety_archive'] = array(
    '#markup' => l('Back to Safety Archive', 'safety_forms/archive', array()),
    '#prefix' => '<div class="safety-form-link">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Validate daily_crane_pre_opt_checklist_form
 */
function daily_crane_pre_opt_checklist_form_validate($form, &$form_state) {
  // Hide default form_state values
  form_state_values_clean($form_state);

  // Collect the values for the fields
  $fields = array(
    'inspected_by' => $form_state['values']['inspected_by'],
    'date' => $form_state['values']['date'],
    'signature' => $form_state['values']['signature'],
  );

  // Unset array values so we can easily serialize the rest of the form data
  unset($form_state['values']['inspected_by']);
  unset($form_state['values']['date']);
  unset($form_state['values']['signature']);

  // Serialize and add crane data to fields
  $fields['crane_data'] = serialize($form_state['values']);
  // Add fields back to form_state values
  $form_state['values']['data'] = array('fields' => $fields);
}


/**
 * Validate daily_crane_pre_opt_checklist_form
 */
function daily_crane_pre_opt_checklist_form_submit($form, &$form_state) {

  $fields = $form_state['values']['data']['fields'];

  $query = db_insert('daily_crane_pre_opt_checklist_form')
    ->fields($fields);

  $query->execute();

  if ($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';

}