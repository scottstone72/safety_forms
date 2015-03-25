<?php
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/weekly_and_pre_job_meeting_form.min.css');

/*
 * Weekly and Pre-Job Meeting Form
 * Implements hook_form()
 */
function weekly_and_pre_job_meeting_form($form, &$form_state) {

  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Weekly and Pre-Job Meeting Form'),
  );

  $form['main_container']['type_cont'] = array(
    '#type' => 'fieldset',
    '#title' => t('Type of Form'),
    '#id' => 'meeting-type',
  );


  $form['main_container']['type_cont']['form_type'] = array(
    '#type' => 'radios',
    '#options' => array(
      'WEEKLY' => 'WEEKLY',
      'JSA REVIEW' => 'JSA REVIEW',
      'PRE-JOB' => 'PRE-JOB',
      'HAZARD ASSESSMENT' => 'HAZARD ASSESSMENT',
    ),
    '#required' => TRUE,
  );

  $form['main_container']['rig'] = array(
    '#type' => 'textfield',
    '#title' => t('Rig'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="rig">',
    '#suffix' => '</div>',
  );

  $form['main_container']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date'),
    '#default_value' => date('M d, Y'),
    '#disabled' => TRUE,
    '#prefix' => '<div class="date">',
    '#suffix' => '</div>',
  );


  $form['main_container']['location'] = array(
    '#type' => 'textfield',
    '#title' => t('Location'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="location">',
    '#suffix' => '</div>',
  );

  $form['main_container']['recorded_by'] = array(
    '#type' => 'textfield',
    '#title' => t('Recorded By'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="recorded-by">',
    '#suffix' => '</div>',
  );

  $form['main_container']['attend_cont'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => t('Attendance (Name, Position, Company)'),
//    '#attributes' => array('class', array('attend-cont')),
    '#id' => 'ajax-name-container',
    '#prefix' => '<div class="attend-cont">',
    '#suffix' => '</div>',
  );

  // $form_state['repairs_req'] to determine the number of textfields to build.
  if (empty($form_state['counter'])) {
    $form_state['counter'] = 1;
  }

  for ($i = 0; $i < $form_state['counter']; $i++) {

    $form['main_container']['attend_cont'][$i]['name'][$i] = array(
      '#type' => 'textfield',
      '#title' => t('Name ' . ($i + 1)),
      '#default_value' => '',
      '#required' => TRUE,
//      '#id' => 'attendance_' . $i,
      '#prefix' => '<div class="attend-name">',
      '#suffix' => '</div>',
    );

    $form['main_container']['attend_cont'][$i]['position'][$i] = array(
      '#type' => 'textfield',
      '#title' => t('Position ' . ($i + 1)),
      '#default_value' => '',
      '#required' => TRUE,
//      '#id' => 'position_' . $i,
      '#prefix' => '<div class="attend-position">',
      '#suffix' => '</div>',
    );

    $form['main_container']['attend_cont'][$i]['company'][$i] = array(
      '#type' => 'textfield',
      '#title' => t('Company ' . ($i + 1)),
      '#default_value' => '',
//      '#id' => 'company_' . $i,
      '#required' => TRUE,
      '#prefix' => '<div class="attend-company">',
      '#suffix' => '</div>',
    );
  }

  // Submit button to add more repairs text fields
  $form['main_container']['attend_cont']['add_name'] = array(
    '#type' => 'submit',
    '#value' => 'Add Name',
    '#submit' => array('jsa_forms_add_name_textfield'),
    '#ajax' => array(
      'callback' => 'ajax_weekly_callback',
      'wrapper' => 'ajax-name-container',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#prefix' => '<div class="add">',
    '#suffix' => '</div>',
  );
  // Submit button to remove repairs text fields
  $form['main_container']['attend_cont']['remove_name'] = array(
    '#type' => 'submit',
    '#value' => 'Remove Name',
    '#submit' => array('jsa_forms_remove_name_textfield'),
    '#ajax' => array(
      'callback' => 'ajax_weekly_callback',
      'wrapper' => 'ajax-name-container',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#prefix' => '<div class="remove">',
    '#suffix' => '</div>',
  );

  $form['main_container']['general_safety_topics'] = array(
    '#type' => 'textarea',
    '#title' => t('General Safety Topics Discussed'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="general-safety-topics">',
    '#suffix' => '</div>',
  );

  $form['main_container']['pre_job_meeting'] = array(
    '#type' => 'textarea',
    '#title' => t('Pre-Job Meeting'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="pre-job-meeting">',
    '#suffix' => '</div>',
  );

  $form['main_container']['jsa_procedure_review'] = array(
    '#type' => 'textarea',
    '#title' => t('JSA/Procedure Review'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="jsa-procedure-review">',
    '#suffix' => '</div>',
  );

  $form['main_container']['hazard_cont'] = array(
    '#type' => 'fieldset',
    '#title' => t('Hazard Assessment'),
    '#id' => 'hazard-access',
  );


  $form['main_container']['hazard_cont']['hazard_assess'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Hazard Assessment'),
    '#title_display' => 'invisible',
    '#options' => array(
      'unlevel_lease' => 'UNLEVEL LEASE',
      'rig_move' => 'RIG MOVE (Traffic, congestion)',
      'weather' => 'WEATHER',
      'overhead_work' => 'OVERHEAD WORK',
      'riggin_ropes_slings' => 'RIGGIN / ROPES / SLINGS',
      'slips_trips_falls' => 'SLIPS / TRIPS / FALLS',
      'confined_space' => 'CONFINED SPACE',
      'electrical_hazards' => 'ELECTRICAL HAZARDS',
      'housekeeping' => 'HOUSEKEEPING',
      'pinch_points' => 'PINCH POINTS',
      'welding' => 'WELDING',
      'cement' => 'CEMENT',
      'equipment_service' => 'EQUIPMENT SERVICE',
      'whmis_products' => 'WHMIS PRODUCTS',
      'h2s' => 'H2S',
      'grinders_hand_tools' => 'GRINDERS & HAND TOOLS',
      'lifting_carrying' => 'LIFTING & CARRYING',
      'noise' => 'NOISE',
      'party_3rd_equip' => '3RD PARTY EQUIPMENT',
      'washgun' => 'WASHGUN',
      'pressure_hazards' => 'PRESSURE HAZARDS',
      'rotating_equip' => 'ROTATING EQUIPMENT',
      'invert' => 'INVERT',
      'working_heights' => 'WORKING AT HEIGHTS',
    ),
    '#required' => TRUE,
//    '#prefix' => '<div class="hazard-access">',
//    '#suffix' => '</div>',
  );

  $form['main_container']['hazard_discuss'] = array(
    '#type' => 'textarea',
    '#title' => t('Hazard Discussed (task, control, etc.)'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="hazard-discuss">',
    '#suffix' => '</div>',
  );


  $form['main_container']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit Weekly and Pre-Job Meeting Form',
    '#executes_submit_callback' => TRUE,
    '#prefix' => '<div class="submit-button">',
    '#suffix' => '</div>',
  );

  return $form;
}


// Ajax function called and used to rebuild form
function ajax_weekly_callback($form, &$form_state) {

  return $form['main_container']['attend_cont'];
}

/**
 * Submit handler for the "add_name" button.
 *
 * Increments the counter to add a field and causes a rebuild.
 */
function jsa_forms_add_name_textfield($form, &$form_state) {

  $form_state['counter']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the "remove_name" button.
 *
 * Decrements the counter to remove a field and causes a form rebuild.
 */
function jsa_forms_remove_name_textfield($form, &$form_state) {

  if ($form_state['counter'] > 1) {
    $form_state['counter']--;
  }
  $form_state['rebuild'] = TRUE;
}


function weekly_and_pre_job_meeting_form_validate($form, &$form_state) {
  
  $name = $position = $company = array();

  for ($i = 0; $i < $form_state['counter']; $i++) {
    // Add the values to array so we can hand over to implode() to convert to comma separated string.
    $name[] = $form_state['values']['attend_cont'][$i]['name'][$i];
    $position[] = $form_state['values']['attend_cont'][$i]['position'][$i];
    $company[] = $form_state['values']['attend_cont'][$i]['company'][$i];
  }

  // Organize and store our repair data
  $attend['info'] = array(
      'name' => $name,
      'position' => $position,
      'company' => $company,
  );
  

  $data = array(
    'attendance' => $attend,
    'general_safety_topics' => $form_state['values']['general_safety_topics'],
    'pre_job_meeting' => $form_state['values']['pre_job_meeting'],
    'jsa_procedure_review' => $form_state['values']['jsa_procedure_review'],
    'unlevel_lease' => $form_state['values']['hazard_assess']['unlevel_lease'],
    'rig_move' => $form_state['values']['hazard_assess']['rig_move'],
    'weather' => $form_state['values']['hazard_assess']['weather'],
    'overhead_work' => $form_state['values']['hazard_assess']['overhead_work'],
    'riggin_ropes_slings' => $form_state['values']['hazard_assess']['riggin_ropes_slings'],
    'slips_trips_falls' => $form_state['values']['hazard_assess']['slips_trips_falls'],
    'confined_space' => $form_state['values']['hazard_assess']['confined_space'],
    'electrical_hazards' => $form_state['values']['hazard_assess']['electrical_hazards'],
    'housekeeping' => $form_state['values']['hazard_assess']['housekeeping'],
    'pinch_points' => $form_state['values']['hazard_assess']['pinch_points'],
    'welding' => $form_state['values']['hazard_assess']['welding'],
    'cement' => $form_state['values']['hazard_assess']['cement'],
    'equipment_service' => $form_state['values']['hazard_assess']['equipment_service'],
    'whmis_products' => $form_state['values']['hazard_assess']['whmis_products'],
    'h2s' => $form_state['values']['hazard_assess']['h2s'],
    'grinders_hand_tools' => $form_state['values']['hazard_assess']['grinders_hand_tools'],
    'lifting_carrying' => $form_state['values']['hazard_assess']['lifting_carrying'],
    'noise' => $form_state['values']['hazard_assess']['noise'],
    'party_3rd_equip' => $form_state['values']['hazard_assess']['party_3rd_equip'],
    'washgun' => $form_state['values']['hazard_assess']['washgun'],
    'pressure_hazards' => $form_state['values']['hazard_assess']['pressure_hazards'],
    'rotating_equip' => $form_state['values']['hazard_assess']['rotating_equip'],
    'invert' => $form_state['values']['hazard_assess']['invert'],
    'working_heights' => $form_state['values']['hazard_assess']['working_heights'],
    'hazard_discuss' => $form_state['values']['hazard_discuss'],
  );


  $form_state['weekly_pre_job_data'] = serialize($data);
}


function weekly_and_pre_job_meeting_form_submit($form, &$form_state) {

  $fields = array(
    'rig' => $form_state['values']['rig'],
    'form_type' => $form_state['values']['form_type'],
//    'weekly' => $form_state['values']['meeting_type']['weekly'],
//    'jsa_review' => $form_state['values']['meeting_type']['jsa_review'],
//    'pre_job' => $form_state['values']['meeting_type']['pre_job'],
//    'hazard_assessment' => $form_state['values']['meeting_type']['hazard_assessment'],
    'date' => $form_state['values']['date'],
    'location' => $form_state['values']['location'],
    'recorded_by' => $form_state['values']['recorded_by'],
    'weekly_pre_job_data' => $form_state['weekly_pre_job_data'],
    'timestamp' => time(),
  );

  $query = db_insert('weekly_and_pre_job_meeting_form')
    ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';
}