<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/jsa_form.min.css');


/*
 * Monthly Meeting Form
 * Implements hook_form()
 */
function jsa_archive_form($form, &$form_state, $args) {

  $jsa = check_plain($args);

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('jsa_form',  $id = NULL, $month = NULL, $year = NULL, $permit_num = NULL, $jsa);

  foreach($safety_data as $key => $val) {

    $image_path = unserialize($val['image_path']);
    $company_image_fid = unserialize($val['company_image_fid']);
    $jsa_form_data = unserialize($val['jsa_form_data']);

    $form['main_container'] = array(
      '#type' => 'fieldset',
      '#id' => 'main-title',
      '#title' => t("Job Safety Analysis Form - JSA# $jsa - Archived"),
    );

    $form['main_container']['jsa_num'] = array(
      '#type' => 'textfield',
      '#title' => t('JSA #'),
      '#default_value' => $val['jsa_num'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="jsa-num">',
      '#suffix' => '</div>',
    );

    $form['main_container']['job_task'] = array(
      '#type' => 'textfield',
      '#title' => t('Job / Task'),
      '#default_value' => $jsa_form_data['job_task'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="job-task">',
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

//    $form['main_container']['page_of'] = array(
//      '#type' => 'textfield',
//      '#title' => t('Page Of'),
//      '#default_value' => $jsa_form_data['page_of'],
//      '#disabled' => TRUE,
//      '#prefix' => '<div class="page-of">',
//      '#suffix' => '</div>',
//    );

    $form['main_container']['rig_num'] = array(
      '#type' => 'textfield',
      '#title' => t('Rig #'),
      '#default_value' => $val['rig_num'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="rig-num">',
      '#suffix' => '</div>',
    );

    $form['main_container']['supervisor'] = array(
      '#type' => 'textfield',
      '#title' => t('Supervisor'),
      '#default_value' => $val['supervisor'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="supervisor">',
      '#suffix' => '</div>',
    );

    $form['main_container']['risk_cont'] = array(
      '#type' => 'container',
      '#title' => t('Risk Assessment'),
      '#id' => 'ajax-risk-assess-cont',
      '#prefix' => '<div class="risk-cont">',
      '#suffix' => '</div>',
    );


    foreach ($jsa_form_data['risk_assess'] as $k => $v) {

    /** Start our Risk Assess element */
    $form['main_container']['risk_cont']['risk_assess'][$k] = array(
      '#type' => 'fieldset',
      '#title' => t('Risk Assessment #' . ($k + 1)),
      '#attributes' => array('class' => array('jsa-analysis-inner')),
    );

    // Add the custom elements
    $form['main_container']['risk_cont']['risk_assess'][$k]['job_steps'] = array(
      '#type' => 'textarea',
      '#title' => t('Job Steps'),
      '#default_value' => $v['job_steps'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="job-steps">',
      '#suffix' => '</div>',
    );

    $form['main_container']['risk_cont']['risk_assess'][$k]['hazards'] = array(
      '#type' => 'textarea',
      '#title' => t('Hazards'),
      '#default_value' => $v['hazards'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="hazards">',
      '#suffix' => '</div>',
    );

    $form['main_container']['risk_cont']['risk_assess'][$k]['risk_level'] = array(
      '#type' => 'select',
      '#title' => t('Risk Level'),
      '#default_value' => $v['risk_level'],
      '#disabled' => TRUE,
      '#options' => array(
        'no_immediate_danger' => 'NO IMMEDIATE DANGER',
        'low' => 'LOW',
        'moderate' => 'MODERATE',
        'high' => 'HIGH',
      ),
      '#prefix' => '<div class="risk-level">',
      '#suffix' => '</div>',
    );

    $form['main_container']['risk_cont']['risk_assess'][$k]['steps_to_control_hazard'] = array(
      '#type' => 'textarea',
      '#title' => t('Steps To Control Hazard'),
      '#default_value' => $v['steps_to_control_hazard'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="job-steps">',
      '#suffix' => '</div>',
    );

    $form['main_container']['risk_cont']['risk_assess'][$k]['control_method'] = array(
      '#type' => 'select',
      '#title' => t('Control Method'),
      '#default_value' => $v['control_method'],
      '#disabled' => TRUE,
      '#options' => array(
        'engineering' => 'ENGINEERING',
        'administration' => 'ADMINISTRATION',
        'ppe' => 'PPE',
      ),
      '#prefix' => '<div class="steps-to-control-hazard">',
      '#suffix' => '</div>',
    );

    $form['main_container']['risk_cont']['risk_assess'][$k]['new_risk_level'] = array(
      '#type' => 'select',
      '#title' => t('New Risk Level'),
      '#default_value' => $v['new_risk_level'],
      '#disabled' => TRUE,
      '#options' => array(
        'no_immediate_danger' => 'NO IMMEDIATE DANGER',
        'low' => 'LOW',
        'moderate' => 'MODERATE',
        'high' => 'HIGH',
      ),
      '#prefix' => '<div class="new-risk-level">',
      '#suffix' => '</div>',
    );

    $form['main_container']['risk_cont']['risk_assess'][$k]['date_reviewed'] = array(
      '#type' => 'textfield',
      '#title' => t('Date JSA Reviewed'),
      '#default_value' => $v['date_reviewed'],
      '#disabled' => TRUE,
      '#attributes' => array('class' => array('ui-datepicker-date-reviewed')),
      '#prefix' => '<div class="date-reviewed">',
      '#suffix' => '</div>',
    );
  }



    $form['main_container']['weak_links'] = array(
      '#type' => 'textarea',
      '#title' => t('Weak Links (Any other unidentified issues that could cause problems)'),
      '#default_value' => $jsa_form_data['weak_links'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="weak-links">',
      '#suffix' => '</div>',
    );

    $form['main_container']['safety_items'] = array(
      '#type' => 'fieldset',
      '#title' => t('Safety Items required for job'),
      '#id' => 'jsa-review-select',
    );

    $form['main_container']['safety_items']['safety_message'] = array(
      '#markup' => '<div class="user-message">PPE - All Jobs - Hard Hat, Safety Glasses, Gloves, Steel Toe Boots, Coveralls, Ear Plugs</div>',
    );

    $form['main_container']['safety_items']['jsa_review_select'] = array(
      '#type' => 'checkboxes',
      '#default_value' => array(
        $jsa_form_data['jsa_review'],
        $jsa_form_data['respirator'],
        $jsa_form_data['scba_saba'],
        $jsa_form_data['safety_signs'],
        $jsa_form_data['lockout'],
        $jsa_form_data['work_vest'],
        $jsa_form_data['apron_rubber_gloves'],
        $jsa_form_data['harness_fall_protection'],
        $jsa_form_data['ventilation'],
        $jsa_form_data['work_permit'],
        $jsa_form_data['reflective_clothing'],
      ),
      '#options' => array(
        'jsa_review' => 'JSA Review',
        'respirator' => 'Respirator',
        'scba_saba' => 'SCBA / SABA',
        'safety_signs' => 'Safety Signs',
        'lockout' => 'Lockout',
        'work_vest' => 'Work Vest',
        'apron_rubber_gloves' => 'Apron / Rubber Gloves',
        'harness_fall_protection' => 'Harness / Fall Protection',
        'ventilation' => 'Ventilation',
        'work_permit' => 'Work Permit',
        'reflective_clothing' => 'Reflective Clothing',
      ),
      '#disabled' => TRUE,
    );


    $form['main_container']['jsa_risk'] = array(
      '#type' => 'container',
      '#title' => t('Job Risk Analysis'),
      '#prefix' => '<div class="job-risk">',
      '#suffix' => '</div>',
    );

    $form['main_container']['jsa_risk']['frequency'] = array(
      '#type' => 'textfield',
      '#title' => t('Frequency (of task)'),
      '#default_value' => $jsa_form_data['frequency'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="frequency">',
      '#suffix' => '</div>',
    );

    $form['main_container']['jsa_risk']['possibility'] = array(
      '#type' => 'textfield',
      '#title' => t('Possibility (of harm)'),
      '#default_value' => $jsa_form_data['possibility'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="possibility">',
      '#suffix' => '</div>',
    );

    $form['main_container']['jsa_risk']['severity'] = array(
      '#type' => 'textfield',
      '#title' => t('Severity (consequence)'),
      '#default_value' => $jsa_form_data['severity'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="frequency">',
      '#suffix' => '</div>',
    );

    $form['main_container']['jsa_risk']['maximum_rank'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum Rank'),
      '#default_value' => $jsa_form_data['maximum_rank'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="maximum-rank">',
      '#suffix' => '</div>',
    );

    $form['main_container']['attached_photos'] = array(
      '#type' => 'radios',
      '#title' => t('Photo\'s attached for critical task'),
      '#id' => 'attached-photos',
      '#default_value' => $val['attached_photos'],
      '#options' => array(
        'no' => 'No',
        'yes' => 'Yes',
      ),
      '#disabled' => TRUE,
      '#prefix' => '<div class="attached-photos">',
      '#suffix' => '</div>',
    );

    $form['main_container']['upload_field'] = array(
      '#type' => 'container',
      '#id' => 'upload-container',
    );

    // Loop through and load and show our images
    foreach ($company_image_fid as $k => $v) {
      $img_obj = file_load($v);

      $variables = array(
        'path' => $img_obj->uri,
        'alt' => 'Uploaded JSA Images',
        'width' => '500px',
        'height' => 'auto',
        'title' => 'Uploaded JSA Images',
        'attributes' => array('class' => array('company-image')),
      );

      $img = theme('image', $variables);

      $form['main_container']['upload_field']['upload'][$k] = array(
        '#markup' => '<div class="uploaded-images">' . $img . '</div>',
      );
    }
  }

  $form['main_container']['link_to_safety_archive'] = array(
    '#markup' => l('Back to Safety Archive', 'safety_forms/archive', array()),
    '#prefix' => '<div class="jsa-link">',
    '#suffix' => '</div>',
  );

  return $form;
}
