<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/weekly_and_pre_job_meeting_form.min.css');

/*
 * Weekly and Pre-Job Meeting Form
 * Implements hook_form()
 */
function weekly_and_pre_job_meeting_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);
  $build = '';

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('weekly_and_pre_job_meeting_form', $id);

  foreach ($safety_data as $key => $val) {
    // Unserialize our data array
    $data = unserialize($val['weekly_pre_job_data']);
    $attendance = array_shift($data); // Grab Attendance data

    $form['main_container'] = array(
      '#type' => 'fieldset',
      //      '#id' => 'weekly-and-pre-job-meeting-form',
      '#title' => t("Weekly and Pre-Job Meeting Form ID# $id - Archived"),
    );

    $form['main_container']['type_cont'] = array(
      '#type' => 'fieldset',
      '#title' => t('Type of Form'),
      '#id' => 'meeting-type',
    );


    $form['main_container']['type_cont']['form_type'] = array(
      '#type' => 'radios',
      '#default_value' => $val['form_type'],
      '#disabled' => TRUE,
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
      '#default_value' => $val['rig'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="rig">',
      '#suffix' => '</div>',
    );

    $form['main_container']['date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date'),
      '#default_value' => $val['date'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="date">',
      '#suffix' => '</div>',
    );


    $form['main_container']['location'] = array(
      '#type' => 'textfield',
      '#title' => t('Location'),
      '#default_value' => $val['location'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="location">',
      '#suffix' => '</div>',
    );

    $form['main_container']['recorded_by'] = array(
      '#type' => 'textfield',
      '#title' => t('Recorded By'),
      '#default_value' => $val['recorded_by'],
      '#disabled' => TRUE,
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

//    // $form_state['repairs_req'] to determine the number of textfields to build.
//    if (empty($form_state['counter'])) {
//      $form_state['counter'] = 1;
//    }

    for ($i = 0; $i < count($attendance); $i++) {

      $form['main_container']['attend_cont'][$i]['name'][$i] = array(
        '#type' => 'textfield',
        '#title' => t('Name ' . ($i + 1)),
        '#default_value' => $attendance['info']['name'][$i],
        '#disabled' => TRUE,
        '#id' => 'attendance_' . $i,
        '#prefix' => '<div class="attend-name">',
        '#suffix' => '</div>',
      );

      $form['main_container']['attend_cont'][$i]['position'][$i] = array(
        '#type' => 'textfield',
        '#title' => t('Position ' . ($i + 1)),
        '#default_value' => $attendance['info']['position'][$i],
        '#disabled' => TRUE,
        '#id' => 'position_' . $i,
        '#prefix' => '<div class="attend-position">',
        '#suffix' => '</div>',
      );

      $form['main_container']['attend_cont'][$i]['company'][$i] = array(
        '#type' => 'textfield',
        '#title' => t('Company ' . ($i + 1)),
        '#default_value' => $attendance['info']['company'][$i],
        '#id' => 'company_' . $i,
        '#disabled' => TRUE,
        '#prefix' => '<div class="attend-company">',
        '#suffix' => '</div>',
      );
    }

    $form['main_container']['general_safety_topics'] = array(
      '#type' => 'textarea',
      '#title' => t('General Safety Topics Discussed'),
      '#default_value' => $data['general_safety_topics'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="general-safety-topics">',
      '#suffix' => '</div>',
    );

    $form['main_container']['pre_job_meeting'] = array(
      '#type' => 'textarea',
      '#title' => t('Pre-Job Meeting'),
      '#default_value' => $data['pre_job_meeting'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="pre-job-meeting">',
      '#suffix' => '</div>',
    );

    $form['main_container']['jsa_procedure_review'] = array(
      '#type' => 'textarea',
      '#title' => t('JSA/Procedure Review'),
      '#default_value' => $data['jsa_procedure_review'],
      '#disabled' => TRUE,
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
      '#default_value' => array(
        $data['unlevel_lease'],
        $data['rig_move'],
        $data['weather'],
        $data['overhead_work'],
        $data['riggin_ropes_slings'],
        $data['slips_trips_falls'],
        $data['confined_space'],
        $data['electrical_hazards'],
        $data['housekeeping'],
        $data['pinch_points'],
        $data['welding'],
        $data['cement'],
        $data['equipment_service'],
        $data['whmis_products'],
        $data['h2s'],
        $data['grinders_hand_tools'],
        $data['lifting_carrying'],
        $data['noise'],
        $data['party_3rd_equip'],
        $data['washgun'],
        $data['pressure_hazards'],
        $data['rotating_equip'],
        $data['invert'],
        $data['working_heights'],
      ),
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
        'pinch_points' => 'PINCH_POINTS',
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
        '#disabled' => TRUE,
    );

    $form['main_container']['hazard_discuss'] = array(
      '#type' => 'textarea',
      '#title' => t('Hazard Discussed (task, control, etc.)'),
      '#default_value' => $data['hazard_discuss'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="hazard-discuss">',
      '#suffix' => '</div>',
    );
  }

  $form['main_container']['link_to_safety_archive'] = array(
    '#markup' => l('Back to Safety Archive', 'safety_forms/archive', array()),
    '#prefix' => '<div class="weekly-link">',
    '#suffix' => '</div>',
  );

  return $form;
}
