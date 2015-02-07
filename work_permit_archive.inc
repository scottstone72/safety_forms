<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/work_permit_form.min.css');

/*
 * Implements hook_form()
 */
function work_permit_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);
  $build = '';

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('work_permits_form', $id);

  foreach($safety_data as $key => $val) {

    $data = unserialize($val['work_permit_data']); // Unserialize our data array
    $rig_site_orient = $data['rig_site_orient'];
    $confined_space = $data['confined_space'];
    $hot_work = $data['hot_work'];
    $lockout = $data['lockout'];
    $high_press_work = $data['high_press_work'];
    $other_form_data = $data['other_form_data'];

    $form['main_container'] = array(
      '#type' => 'fieldset',
      '#title' => t("Work Permit Form - Permit # $id - Archived"),
    );

    $form['main_container']['auth_for_work_serv'] = array(
      '#type' => 'fieldset',
      '#title' => t('Safe Work Permit / Authorization for Work or Service'),
    );

    $form['main_container']['auth_for_work_serv']['permit_num'] = array(
      '#type' => 'textfield',
      '#title' => t('Permit No.'),
      '#default_value' => $val['permit_num'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="permit-num">',
      '#suffix' => '</div>',
    );

    $form['main_container']['auth_for_work_serv']['date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date'),
      '#disabled' => TRUE,
      '#default_value' => $val['date'],
      '#prefix' => '<div class="date">',
      '#suffix' => '</div>',
    );

    $form['main_container']['auth_for_work_serv']['issued_to'] = array(
      '#type' => 'textfield',
      '#title' => t('Issued To'),
      '#default_value' => $val['issued_to'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="issued-to">',
      '#suffix' => '</div>',
    );

    $form['main_container']['auth_for_work_serv']['location_work'] = array(
      '#type' => 'textarea',
      '#title' => t('Location of Work'),
      '#default_value' => $val['location_work'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="location">',
      '#suffix' => '</div>',
    );

    $form['main_container']['auth_for_work_serv']['scope_work'] = array(
      '#type' => 'textarea',
      '#title' => t('Scope of Work'),
      '#default_value' => $other_form_data['scope_work'],
      '#disabled' => TRUE,
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
      '#default_value' => $val['permit_type'],
      '#disabled' => TRUE,
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
      '#default_value' => $val['other_permit'],
      '#disabled' => TRUE,
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
      '#default_value' => $val['hazard_prior_stat'],
      '#disabled' => TRUE,
      '#options' => array(
        'low' => 'Low',
        'medium' => 'Medium',
        'high' => 'High',
      ),
      '#empty_option' => t('Select Priority'),
      '#prefix' => '<div class="hazard-prior-stat">',
      '#suffix' => '</div>',
    );

    $form['main_container']['pre_job_hazard_id']['hazard'] = array(
      '#type' => 'textarea',
      '#title' => t('Hazard'),
      '#default_value' => $other_form_data['hazard'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="hazard">',
      '#suffix' => '</div>',
    );

    $form['main_container']['pre_job_hazard_id']['control'] = array(
      '#type' => 'textarea',
      '#title' => t('Control'),
      '#default_value' => $other_form_data['control'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="control">',
      '#suffix' => '</div>',
    );

    $form['main_container']['pre_job_hazard_id']['rig_driller_approv'] = array(
      '#type' => 'textfield',
      '#title' => t('Rig Manager or Driller Approval'),
      '#default_value' => $other_form_data['rig_driller_approv'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="rig-driller-approv">',
      '#suffix' => '</div>',
    );

    $form['main_container']['pre_job_hazard_id']['valid_from'] = array(
      '#type' => 'textfield',
      '#title' => t('Valid From'),
      '#default_value' => $val['valid_from'],
      '#disabled' => TRUE,
      '#attributes' => array('class' => array('ui-datepicker-valid-from')),
      '#prefix' => '<div class="valid-from">',
      '#suffix' => '</div>',
    );

    $form['main_container']['pre_job_hazard_id']['valid_to'] = array(
      '#type' => 'textfield',
      '#title' => t('Valid To'),
      '#default_value' => $val['valid_to'],
      '#disabled' => TRUE,
      '#attributes' => array('class' => array('ui-datepicker-valid-to')),
      '#prefix' => '<div class="valid-to">',
      '#suffix' => '</div>',
    );

    $form['main_container']['pre_job_hazard_id']['renewed_from'] = array(
      '#type' => 'textfield',
      '#title' => t('Renewed From'),
      '#default_value' => $val['renewed_from'],
      '#disabled' => TRUE,
//      '#attributes' => array('class' => array('ui-datepicker-renewed')),
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
    );

    // Start form elements
    $form['main_container']['rig_site_orient']['job_orient'] = array(
      '#type' => 'checkbox',
      '#title' => t('Job discussion with worker/contractor'),
      '#default_value' => $rig_site_orient['job_orient'],
      '#disabled' => TRUE,
    );

    $form['main_container']['rig_site_orient']['pre_job_orient'] = array(
      '#type' => 'checkbox',
      '#title' => t('Pre Job Safety meetings required (JSA, Risk Assessment, etc.)'),
      '#default_value' => $rig_site_orient['pre_job_orient'],
      '#disabled' => TRUE,
    );

    $form['main_container']['rig_site_orient']['safe_access_orient'] = array(
      '#type' => 'checkbox',
      '#title' => t('Safe access & egress form work areas identified'),
      '#default_value' => $rig_site_orient['safe_access_orient'],
      '#disabled' => TRUE,
    );

    $form['main_container']['rig_site_orient']['protect_clothing_orient'] = array(
      '#type' => 'checkbox',
      '#title' => t('Protective clothing: FR clothing, High Visibility, Safety Glasses w/shields, Hardhats, Steel Toe Boots'),
      '#default_value' => $rig_site_orient['protect_clothing_orient'],
      '#disabled' => TRUE,
    );

    $form['main_container']['rig_site_orient']['special_safety_orient'] = array(
      '#type' => 'checkbox',
      '#title' => t('Special safety equipment requirements, Grounding/Bonding Cables, Explosion Proof Electrical Equipment, Scaffolding, Hole Covers/Barricades'),
      '#default_value' => $rig_site_orient['special_safety_orient'],
      '#disabled' => TRUE,
    );

    $form['main_container']['rig_site_orient']['radio_orient'] = array(
      '#type' => 'checkbox',
      '#title' => t('Radio or electrical equipment restriction'),
      '#default_value' => $rig_site_orient['radio_orient'],
      '#disabled' => TRUE,
    );

    $form['main_container']['rig_site_orient']['special_cert'] = array(
      '#type' => 'checkbox',
      '#title' => t('Special certificates needed : H2S, WHMIS, B Pressure ticket etc.'),
      '#default_value' => $rig_site_orient['special_cert'],
      '#disabled' => TRUE,
    );

    $form['main_container']['rig_site_orient']['wcb'] = array(
      '#type' => 'checkbox',
      '#title' => t('WCB coverage'),
      '#default_value' => $rig_site_orient['wcb'],
      '#disabled' => TRUE,
    );

    $form['main_container']['rig_site_orient']['smoking'] = array(
      '#type' => 'checkbox',
      '#title' => t('Smoking policy & assigned area'),
      '#default_value' => $rig_site_orient['smoking'],
      '#disabled' => TRUE,
    );

    $form['main_container']['rig_site_orient']['report_incidents'] = array(
      '#type' => 'checkbox',
      '#title' => t('Report all Incidents, near misses or hazards'),
      '#default_value' => $rig_site_orient['report_incidents'],
      '#disabled' => TRUE,
    );

    $form['main_container']['rig_site_orient']['pay_attention'] = array(
      '#type' => 'checkbox',
      '#title' => t('Pay attention to all rig signs, rig alarms & restricted areas'),
      '#default_value' => $rig_site_orient['pay_attention'],
      '#disabled' => TRUE,
    );


    $form['main_container']['confined_space'] = array(
      '#type' => 'fieldset',
      '#title' => t('Confined Spaces Entry'),
      '#id' => 'confined-container',
    );

    $form['main_container']['confined_space']['toxic_gas'] = array(
      '#type' => 'checkbox',
      '#title' => t('Toxic gas test'),
      '#default_value' => $confined_space['toxic_gas'],
      '#disabled' => TRUE,
    );

    $form['main_container']['confined_space']['oxygen'] = array(
      '#type' => 'checkbox',
      '#title' => t('Oxygen deficiency test'),
      '#default_value' => $confined_space['oxygen'],
      '#disabled' => TRUE,
    );

    $form['main_container']['confined_space']['continuous_gas'] = array(
      '#type' => 'checkbox',
      '#title' => t('Continuous gas monitoring'),
      '#default_value' => $confined_space['continuous_gas'],
      '#disabled' => TRUE,
    );

    $form['main_container']['confined_space']['designated_rescue'] = array(
      '#type' => 'checkbox',
      '#title' => t('Designated rescue team or alternate means of rescue'),
      '#default_value' => $confined_space['designated_rescue'],
      '#disabled' => TRUE,
    );

    $form['main_container']['confined_space']['safety_harness'] = array(
      '#type' => 'checkbox',
      '#title' => t('Safety Harness & Life Line'),
      '#default_value' => $confined_space['safety_harness'],
      '#disabled' => TRUE,
    );

    $form['main_container']['confined_space']['breathing_air'] = array(
      '#type' => 'checkbox',
      '#title' => t('Breathing Air Mask required'),
      '#default_value' => $confined_space['breathing_air'],
      '#disabled' => TRUE,
    );

    $form['main_container']['confined_space']['equip_ventilated'] = array(
      '#type' => 'checkbox',
      '#title' => t('Equipment/Vessels ventilated'),
      '#default_value' => $confined_space['equip_ventilated'],
      '#disabled' => TRUE,
    );

    $form['main_container']['confined_space']['lock_out'] = array(
      '#type' => 'checkbox',
      '#title' => t('Lock Out procedure review'),
      '#default_value' => $confined_space['lock_out'],
      '#disabled' => TRUE,
    );

    $form['main_container']['confined_space']['task'] = array(
      '#type' => 'checkbox',
      '#title' => t('Task supervision requirements'),
      '#default_value' => $confined_space['task'],
      '#disabled' => TRUE,
    );

    $form['main_container']['confined_space']['communication'] = array(
      '#type' => 'checkbox',
      '#title' => t('Communications equipment available'),
      '#default_value' => $confined_space['communication'],
      '#disabled' => TRUE,
    );

    $form['main_container']['hot_work'] = array(
      '#type' => 'fieldset',
      '#title' => t('Hot Work'),
      '#id' => 'hot-work',
    );

    $form['main_container']['hot_work']['explosive_gas'] = array(
      '#type' => 'checkbox',
      '#title' => t('Explosive gas test'),
      '#default_value' => $hot_work['explosive_gas'],
      '#disabled' => TRUE,
    );

    $form['main_container']['hot_work']['continuous_air'] = array(
      '#type' => 'checkbox',
      '#title' => t('Continuous air monitoring'),
      '#default_value' => $hot_work['continuous_air'],
      '#disabled' => TRUE,
    );

    $form['main_container']['hot_work']['task_super'] = array(
      '#type' => 'checkbox',
      '#title' => t('Task supervision requirements'),
      '#default_value' => $hot_work['task_super'],
      '#disabled' => TRUE,
    );

    $form['main_container']['hot_work']['fire_watch'] = array(
      '#type' => 'checkbox',
      '#title' => t('Fire watch personnel required & assigned'),
      '#default_value' => $hot_work['fire_watch'],
      '#disabled' => TRUE,
    );

    $form['main_container']['hot_work']['combust_materials'] = array(
      '#type' => 'checkbox',
      '#title' => t('Combustible materials removed/protected'),
      '#default_value' => $hot_work['combust_materials'],
      '#disabled' => TRUE,
    );

    $form['main_container']['hot_work']['fire_suppr'] = array(
      '#type' => 'checkbox',
      '#title' => t('Fire Suppression equipment requirements & availability'),
      '#default_value' => $hot_work['fire_suppr'],
      '#disabled' => TRUE,
    );

    $form['main_container']['hot_work']['vessels_inspect'] = array(
      '#type' => 'checkbox',
      '#title' => t('Vessles/Lines purged, inerted or depressurized'),
      '#default_value' => $hot_work['vessels_inspect'],
      '#disabled' => TRUE,
    );

    $form['main_container']['hot_work']['welding_equip'] = array(
      '#type' => 'checkbox',
      '#title' => t('Welding Equipment inspected & check valves in cutting torches'),
      '#default_value' => $hot_work['welding_equip'],
      '#disabled' => TRUE,
    );

    $form['main_container']['lock_out_tag'] = array(
      '#type' => 'fieldset',
      '#title' => t('Lock Out / Tag Out'),
      '#id' => 'lock-out-tag',
    );

    $form['main_container']['lock_out_tag']['review_repair'] = array(
      '#type' => 'checkbox',
      '#title' => t('Review repair or servicing task'),
      '#default_value' => $lockout['review_repair'],
      '#disabled' => TRUE,
    );

    $form['main_container']['lock_out_tag']['power_energy_src'] = array(
      '#type' => 'checkbox',
      '#title' => t('Power or energy source is de-energized & locked out'),
      '#default_value' => $lockout['power_energy_src'],
      '#disabled' => TRUE,
    );

    $form['main_container']['lock_out_tag']['not_operate_lockout'] = array(
      '#type' => 'checkbox',
      '#title' => t('Attach a "Do Not Operate" tag to the controls'),
      '#default_value' => $lockout['not_operate_lockout'],
      '#disabled' => TRUE,
    );

    $form['main_container']['lock_out_tag']['key_person'] = array(
      '#type' => 'checkbox',
      '#title' => t('Key kept by the person who puts on the lock'),
      '#default_value' => $lockout['key_person'],
      '#disabled' => TRUE,
    );

    $form['main_container']['lock_out_tag']['test_equip'] = array(
      '#type' => 'checkbox',
      '#title' => t('Test or try equipment'),
      '#default_value' => $lockout['test_equip'],
      '#disabled' => TRUE,
    );

    $form['main_container']['lock_out_tag']['inform_driller'] = array(
      '#type' => 'checkbox',
      '#title' => t('Inform Driller of Lock out\'s in place'),
      '#default_value' => $lockout['inform_driller'],
      '#disabled' => TRUE,
    );

    $form['main_container']['lock_out_tag']['record_tour_book'] = array(
      '#type' => 'checkbox',
      '#title' => t('Record in Tour book, Lock outs in place at crew change'),
      '#default_value' => $lockout['record_tour_book'],
      '#disabled' => TRUE,
    );

    $form['main_container']['lock_out_tag']['rig_man_duplicate'] = array(
      '#type' => 'checkbox',
      '#title' => t('Rig Manager has duplicate set of keys'),
      '#default_value' => $lockout['rig_man_duplicate'],
      '#disabled' => TRUE,
    );

    $form['main_container']['high_press_work'] = array(
      '#type' => 'fieldset',
      '#title' => t('High Pressure Work'),
      '#id' => 'high-press-work',
    );

    $form['main_container']['high_press_work']['review_repair_service'] = array(
      '#type' => 'checkbox',
      '#title' => t('Review repair or servicing task'),
      '#default_value' => $high_press_work['review_repair_service'],
      '#disabled' => TRUE,
    );

    $form['main_container']['high_press_work']['identify_press'] = array(
      '#type' => 'checkbox',
      '#title' => t('Identify pressures & high pressure system'),
      '#default_value' => $high_press_work['identify_press'],
      '#disabled' => TRUE,
    );

    $form['main_container']['high_press_work']['pre_job_meet'] = array(
      '#type' => 'checkbox',
      '#title' => t('Pre-Job meeting'),
      '#default_value' => $high_press_work['pre_job_meet'],
      '#disabled' => TRUE,
    );

    $form['main_container']['high_press_work']['not_operate_hot'] = array(
      '#type' => 'checkbox',
      '#title' => t('"Do Not Operate" Tag or Lock out in place'),
      '#default_value' => $high_press_work['not_operate_hot'],
      '#disabled' => TRUE,
    );

    $form['main_container']['high_press_work']['inform_workers'] = array(
      '#type' => 'checkbox',
      '#title' => t('Inform all workers of restricted area'),
      '#default_value' => $high_press_work['inform_workers'],
      '#disabled' => TRUE,
    );

    $form['main_container']['high_press_work']['task_supper'] = array(
      '#type' => 'checkbox',
      '#title' => t('Task supervision requirements'),
      '#default_value' => $high_press_work['task_supper'],
      '#disabled' => TRUE,
    );
  }

  $form['main_container']['link_to_safety_archive'] = array(
    '#markup' => l('Back to Safety Archive', 'safety_forms/archive', array()),
    '#prefix' => '<div class="permit-link">',
    '#suffix' => '</div>',
  );

  return $form;
}
