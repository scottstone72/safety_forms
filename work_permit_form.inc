<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/work_permit_form.min.css');
drupal_add_js(drupal_get_path('module', 'safety_forms') . '/dist/js/safety_forms_ajax_get_form.min.js');

/*
 * Implements hook_form()
 */
function work_permits_form($form, &$form_state) {

  $work_permit_obj = new Safety_Forms();
  $permit_num = $work_permit_obj->get_work_permit_num();

  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Work Permit Form'),
  );

  $form['main_container']['auth_for_work_serv'] = array(
    '#type' => 'fieldset',
    '#title' => t('Safe Work Permit / Authorization for Work or Service'),
  );

  $form['main_container']['auth_for_work_serv']['permit_num'] = array(
    '#type' => 'textfield',
    '#title' => t('Permit No.'),
    '#default_value' => $permit_num,
    '#disabled' => TRUE,
    '#prefix' => '<div class="permit-num">',
    '#suffix' => '</div>',
  );

  $form['main_container']['auth_for_work_serv']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date'),
    '#disabled' => TRUE,
    '#default_value' => date('M d, Y'),
    '#prefix' => '<div class="date">',
    '#suffix' => '</div>',
  );

  $form['main_container']['auth_for_work_serv']['issued_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Issued To'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="issued-to">',
    '#suffix' => '</div>',
  );

  $form['main_container']['auth_for_work_serv']['location_work'] = array(
    '#type' => 'textarea',
    '#title' => t('Location of Work'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="location">',
    '#suffix' => '</div>',
  );

  $form['main_container']['auth_for_work_serv']['scope_work'] = array(
    '#type' => 'textarea',
    '#title' => t('Scope of Work'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="scope">',
    '#suffix' => '</div>',
  );

  $form['main_container']['permit_for'] = array(
    '#type' => 'fieldset',
    '#title' => t('Permit Type'),
    '#id' => 'permit-type',
  );

  $form['main_container']['permit_for']['permit_type'] = array(
    '#type' => 'radios',
    '#title' => t('Permit Type'),
    '#title_display' => 'invisible',
    '#description' => '',
    '#required' => TRUE,
    '#options' => array(
      'rig_site_orientation' => 'Rig Site Orientation',
      'cold_work' => 'Cold Work',
      'hot_work' => 'Hot Work',
      'electrical' => 'Electrical Work',
      'lockout_tagout' => 'Lockout/Tag out',
      'high_press' => 'High Pressure Work',
      'tank_cleaning' => 'Tank Cleaning',
      'confined_entry' => 'Confined Space Entry',
      'other' => 'Other',
    ),
  );


  $form['main_container']['permit_for']['other_permit'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Permit'),
//    '#required' => TRUE,
    '#prefix' => '<div class="other-permit">',
    '#suffix' => '</div>',
  );

  $form['main_container']['pre_job_hazard_id'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pre-Job Hazard Identification and Controls'),
  );

  $form['main_container']['pre_job_hazard_id']['hazard_prior_stat'] = array(
    '#type' => 'select',
    '#title' => t('Hazard Priority Status'),
    '#options' => array(
      'low' => 'Low',
      'medium' => 'Medium',
      'high' => 'High',
    ),
    '#empty_option' => t('Select Priority'),
    '#required' => TRUE,
    '#prefix' => '<div class="hazard-prior-stat">',
    '#suffix' => '</div>',
  );

  $form['main_container']['pre_job_hazard_id']['hazard'] = array(
    '#type' => 'textarea',
    '#title' => t('Hazard'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="hazard">',
    '#suffix' => '</div>',
  );

  $form['main_container']['pre_job_hazard_id']['control'] = array(
    '#type' => 'textarea',
    '#title' => t('Control'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="control">',
    '#suffix' => '</div>',
  );

  $form['main_container']['pre_job_hazard_id']['rig_driller_approv'] = array(
    '#type' => 'textfield',
    '#title' => t('Rig Manager or Driller Approval'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="rig-driller-approv">',
    '#suffix' => '</div>',
  );

  $form['main_container']['pre_job_hazard_id']['valid_from'] = array(
    '#type' => 'textfield',
    '#title' => t('Valid From'),
    '#default_value' => '',
    '#required' => TRUE,
    '#attributes' => array('class' => array('ui-datepicker-valid-from')),
    '#prefix' => '<div class="valid-from">',
    '#suffix' => '</div>',
  );

  $form['main_container']['pre_job_hazard_id']['valid_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Valid To'),
    '#default_value' => '',
    '#required' => TRUE,
    '#attributes' => array('class' => array('ui-datepicker-valid-to')),
    '#prefix' => '<div class="valid-to">',
    '#suffix' => '</div>',
  );

  $form['main_container']['pre_job_hazard_id']['renewed_from'] = array(
    '#type' => 'textfield',
    '#title' => t('Renewed From'),
    '#default_value' => '',
    '#required' => TRUE,
    '#attributes' => array('class' => array('ui-datepicker-renewed')),
    '#prefix' => '<div class="renewed-from">',
    '#suffix' => '</div>',
  );

  $form['main_container']['message'] = array(
    '#markup' => '<div class="user-message">This permit is valid only as long as
                    work conditions existing at the time of its issuance continue,
                    and expires upon occurrence of any drastic operating or
                    hazardous condition changes.</div>',
  );

  $form['main_container']['rig_site_orient'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rig Site Orientation (For all Visitors, Workers or Contractors)'),
    '#id' => 'rig-site-orientation',
//    '#prefix' => '<div class="rig-site-orientation">',
//    '#suffix' => '</div>',
  );

  // Start form elements
  $form['main_container']['rig_site_orient']['job_orient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Job discussion with worker/contractor'),
    '#required' => TRUE,
  );

  $form['main_container']['rig_site_orient']['pre_job_orient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pre Job Safety meetings required (JSA, Risk Assessment, etc.)'),
    '#required' => TRUE,
  );

  $form['main_container']['rig_site_orient']['safe_access_orient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Safe access & egress form work areas identified'),
    '#required' => TRUE,
  );

  $form['main_container']['rig_site_orient']['protect_clothing_orient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Protective clothing: FR clothing, High Visibility, Safety Glasses w/shields, Hardhats, Steel Toe Boots'),
    '#required' => TRUE,
  );

  $form['main_container']['rig_site_orient']['special_safety_orient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Special safety equipment requirements, Grounding/Bonding Cables, Explosion Proof Electrical Equipment, Scaffolding, Hole Covers/Barricades'),
    '#required' => TRUE,
  );

  $form['main_container']['rig_site_orient']['radio_orient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Radio or electrical equipment restriction'),
    '#required' => TRUE,
  );

  $form['main_container']['rig_site_orient']['special_cert'] = array(
    '#type' => 'checkbox',
    '#title' => t('Special certificates needed : H2S, WHMIS, B Pressure ticket etc.'),
    '#required' => TRUE,
  );

  $form['main_container']['rig_site_orient']['wcb'] = array(
    '#type' => 'checkbox',
    '#title' => t('WCB coverage'),
    '#required' => TRUE,
  );

  $form['main_container']['rig_site_orient']['smoking'] = array(
    '#type' => 'checkbox',
    '#title' => t('Smoking policy & assigned area'),
    '#required' => TRUE,
  );

  $form['main_container']['rig_site_orient']['report_incidents'] = array(
    '#type' => 'checkbox',
    '#title' => t('Report all Incidents, near misses or hazards'),
    '#required' => TRUE,
  );

  $form['main_container']['rig_site_orient']['pay_attention'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pay attention to all rig signs, rig alarms & restricted areas'),
    '#required' => TRUE,
  );


  $form['main_container']['confined_space'] = array(
    '#type' => 'fieldset',
    '#title' => t('Confined Spaces Entry'),
    '#id' => 'confined-container',
  );

  $form['main_container']['confined_space']['toxic_gas'] = array(
    '#type' => 'checkbox',
    '#title' => t('Toxic gas test'),
    '#required' => TRUE,
  );

  $form['main_container']['confined_space']['oxygen'] = array(
    '#type' => 'checkbox',
    '#title' => t('Oxygen deficiency test'),
    '#required' => TRUE,
  );

  $form['main_container']['confined_space']['continuous_gas'] = array(
    '#type' => 'checkbox',
    '#title' => t('Continuous gas monitoring'),
    '#required' => TRUE,
  );

  $form['main_container']['confined_space']['designated_rescue'] = array(
    '#type' => 'checkbox',
    '#title' => t('Designated rescue team or alternate means of rescue'),
    '#required' => TRUE,
  );

  $form['main_container']['confined_space']['safety_harness'] = array(
    '#type' => 'checkbox',
    '#title' => t('Safety Harness & Life Line'),
    '#required' => TRUE,
  );

  $form['main_container']['confined_space']['breathing_air'] = array(
    '#type' => 'checkbox',
    '#title' => t('Breathing Air Mask required'),
    '#required' => TRUE,
  );

  $form['main_container']['confined_space']['equip_ventilated'] = array(
    '#type' => 'checkbox',
    '#title' => t('Equipment/Vessels ventilated'),
    '#required' => TRUE,
  );

  $form['main_container']['confined_space']['lock_out'] = array(
    '#type' => 'checkbox',
    '#title' => t('Lock Out procedure review'),
    '#required' => TRUE,
  );

  $form['main_container']['confined_space']['task'] = array(
    '#type' => 'checkbox',
    '#title' => t('Task supervision requirements'),
    '#required' => TRUE,
  );

  $form['main_container']['confined_space']['communication'] = array(
    '#type' => 'checkbox',
    '#title' => t('Communications equipment available'),
    '#required' => TRUE,
  );

  $form['main_container']['hot_work'] = array(
    '#type' => 'fieldset',
    '#title' => t('Hot Work'),
    '#id' => 'hot-work',
  );

  $form['main_container']['hot_work']['explosive_gas'] = array(
    '#type' => 'checkbox',
    '#title' => t('Explosive gas test'),
    '#required' => TRUE,
  );

  $form['main_container']['hot_work']['continuous_air'] = array(
    '#type' => 'checkbox',
    '#title' => t('Continuous air monitoring'),
    '#required' => TRUE,
  );

  $form['main_container']['hot_work']['task_super'] = array(
    '#type' => 'checkbox',
    '#title' => t('Task supervision requirements'),
    '#required' => TRUE,
  );

  $form['main_container']['hot_work']['fire_watch'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fire watch personnel required & assigned'),
    '#required' => TRUE,
  );

  $form['main_container']['hot_work']['combust_materials'] = array(
    '#type' => 'checkbox',
    '#title' => t('Combustible materials removed/protected'),
    '#required' => TRUE,
  );

  $form['main_container']['hot_work']['fire_suppr'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fire Suppression equipment requirements & availability'),
    '#required' => TRUE,
  );

  $form['main_container']['hot_work']['vessels_inspect'] = array(
    '#type' => 'checkbox',
    '#title' => t('Vessles/Lines purged, inerted or depressurized'),
    '#required' => TRUE,
  );

  $form['main_container']['hot_work']['welding_equip'] = array(
    '#type' => 'checkbox',
    '#title' => t('Welding Equipment inspected & check valves in cutting torches'),
    '#required' => TRUE,
  );

  $form['main_container']['lock_out_tag'] = array(
    '#type' => 'fieldset',
    '#title' => t('Lock Out / Tag Out'),
    '#id' => 'lock-out-tag',
  );

  $form['main_container']['lock_out_tag']['review_repair'] = array(
    '#type' => 'checkbox',
    '#title' => t('Review repair or servicing task'),
    '#required' => TRUE,
  );

  $form['main_container']['lock_out_tag']['power_energy_src'] = array(
    '#type' => 'checkbox',
    '#title' => t('Power or energy source is de-energized & locked out'),
    '#required' => TRUE,
  );

  $form['main_container']['lock_out_tag']['not_operate_lockout'] = array(
    '#type' => 'checkbox',
    '#title' => t('Attach a "Do Not Operate" tag to the controls'),
    '#required' => TRUE,
  );

  $form['main_container']['lock_out_tag']['key_person'] = array(
    '#type' => 'checkbox',
    '#title' => t('Key kept by the person who puts on the lock'),
    '#required' => TRUE,
  );

  $form['main_container']['lock_out_tag']['test_equip'] = array(
    '#type' => 'checkbox',
    '#title' => t('Test or try equipment'),
    '#required' => TRUE,
  );

  $form['main_container']['lock_out_tag']['inform_driller'] = array(
    '#type' => 'checkbox',
    '#title' => t('Inform Driller of Lock out\'s in place'),
    '#required' => TRUE,
  );

  $form['main_container']['lock_out_tag']['record_tour_book'] = array(
    '#type' => 'checkbox',
    '#title' => t('Record in Tour book, Lock outs in place at crew change'),
    '#required' => TRUE,
  );

  $form['main_container']['lock_out_tag']['rig_man_duplicate'] = array(
    '#type' => 'checkbox',
    '#title' => t('Rig Manager has duplicate set of keys'),
    '#required' => TRUE,
  );

  $form['main_container']['high_press_work'] = array(
    '#type' => 'fieldset',
    '#title' => t('High Pressure Work'),
    '#id' => 'high-press-work',
  );

  $form['main_container']['high_press_work']['review_repair_service'] = array(
    '#type' => 'checkbox',
    '#title' => t('Review repair or servicing task'),
    '#required' => TRUE,
  );

  $form['main_container']['high_press_work']['identify_press'] = array(
    '#type' => 'checkbox',
    '#title' => t('Identify pressures & high pressure system'),
    '#required' => TRUE,
  );

  $form['main_container']['high_press_work']['pre_job_meet'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pre-Job meeting'),
    '#required' => TRUE,
  );

  $form['main_container']['high_press_work']['not_operate_hot'] = array(
    '#type' => 'checkbox',
    '#title' => t('"Do Not Operate" Tag or Lock out in place'),
    '#required' => TRUE,
  );

  $form['main_container']['high_press_work']['inform_workers'] = array(
    '#type' => 'checkbox',
    '#title' => t('Inform all workers of restricted area'),
    '#required' => TRUE,
  );

  $form['main_container']['high_press_work']['task_supper'] = array(
    '#type' => 'checkbox',
    '#title' => t('Task supervision requirements'),
    '#required' => TRUE,
  );



  $form['main_container']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit Work Permit Form',
    '#executes_submit_callback' => TRUE,
    '#prefix' => '<div class="submit-button">',
    '#suffix' => '</div>',
  );


  return $form;
}

function work_permits_form_validate($form, &$form_state) {

  $data = array(
    'rig_site_orient' => array(
    'job_orient' => $form_state['values']['job_orient'],
    'pre_job_orient' => $form_state['values']['pre_job_orient'],
    'safe_access_orient' => $form_state['values']['safe_access_orient'],
    'protect_clothing_orient' => $form_state['values']['protect_clothing_orient'],
    'special_safety_orient' => $form_state['values']['special_safety_orient'],
    'radio_orient' => $form_state['values']['radio_orient'],
    'special_cert' => $form_state['values']['special_cert'],
    'wcb' => $form_state['values']['wcb'],
    'smoking' => $form_state['values']['smoking'],
    'report_incidents' => $form_state['values']['report_incidents'],
    'pay_attention' => $form_state['values']['pay_attention'],
    ),
    'confined_space' => array(
      'toxic_gas' => $form_state['values']['toxic_gas'],
      'oxygen' => $form_state['values']['oxygen'],
      'continuous_gas' => $form_state['values']['continuous_gas'],
      'designated_rescue' => $form_state['values']['designated_rescue'],
      'safety_harness' => $form_state['values']['safety_harness'],
      'breathing_air' => $form_state['values']['breathing_air'],
      'equip_ventilated' => $form_state['values']['equip_ventilated'],
      'lock_out' => $form_state['values']['lock_out'],
      'task' => $form_state['values']['task'],
      'communication' => $form_state['values']['communication'],
    ),
    'hot_work' => array(
      'explosive_gas' => $form_state['values']['explosive_gas'],
      'continuous_air' => $form_state['values']['continuous_air'],
      'task_super' => $form_state['values']['task_super'],
      'fire_watch' => $form_state['values']['fire_watch'],
      'combust_materials' => $form_state['values']['combust_materials'],
      'fire_suppr' => $form_state['values']['fire_suppr'],
      'vessels_inspect' => $form_state['values']['vessels_inspect'],
      'welding_equip' => $form_state['values']['welding_equip'],
    ),
    'lockout' => array(
      'review_repair' => $form_state['values']['review_repair'],
      'power_energy_src' => $form_state['values']['power_energy_src'],
      'not_operate_lockout' => $form_state['values']['not_operate_lockout'],
      'key_person' => $form_state['values']['key_person'],
      'test_equip' => $form_state['values']['test_equip'],
      'inform_driller' => $form_state['values']['inform_driller'],
      'record_tour_book' => $form_state['values']['record_tour_book'],
      'rig_man_duplicate' => $form_state['values']['rig_man_duplicate'],
    ),
    'high_press_work' => array(
      'review_repair_service' => $form_state['values']['review_repair_service'],
      'identify_press' => $form_state['values']['identify_press'],
      'pre_job_meet' => $form_state['values']['pre_job_meet'],
      'not_operate_hot' => $form_state['values']['not_operate_hot'],
      'inform_workers' => $form_state['values']['inform_workers'],
      'task_supper' => $form_state['values']['task_supper'],
    ),
    'other_form_data' => array(
      'scope_work' => $form_state['values']['scope_work'],
      'hazard' => $form_state['values']['hazard'],
      'control' => $form_state['values']['control'],
      'rig_driller_approv' => $form_state['values']['rig_driller_approv'],
    ),
  );

  $form_state['work_permit_data'] = serialize($data);
}

function work_permits_form_submit($form, &$form_state) {

  $fields = array(
    'permit_num' => $form_state['values']['permit_num'],
    'date' => $form_state['values']['date'],
    'issued_to' => $form_state['values']['issued_to'],
    'location_work' => $form_state['values']['location_work'],
    'permit_type' => $form_state['values']['permit_type'],
//    'rig_site_orientation' => $form_state['values']['rig_site_orientation'],
//    'cold_work' => $form_state['values']['cold_work'],
//    'hot_work' => $form_state['values']['hot_work'],
//    'electrical' => $form_state['values']['electrical'],
//    'lockout_tagout' => $form_state['values']['lockout_tagout'],
//    'high_press' => $form_state['values']['high_press'],
//    'tank_cleaning' => $form_state['values']['tank_cleaning'],
//    'confined_entry' => $form_state['values']['confined_entry'],
    'other_permit' => $form_state['values']['other_permit'],
    'hazard_prior_stat' => $form_state['values']['hazard_prior_stat'],
    'valid_from' => $form_state['values']['valid_from'],
    'valid_to' => $form_state['values']['valid_to'],
    'renewed_from' => $form_state['values']['renewed_from'],
    'work_permit_data' => $form_state['work_permit_data'],
    'timestamp' => time(),
  );


  $query = db_insert('work_permits_form')
    ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';
}
