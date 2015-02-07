<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/jsa_form.min.css');
drupal_add_js(drupal_get_path('module', 'safety_forms') . '/dist/js/safety_forms_ajax_get_form.min.js');

/*
 * Monthly Meeting Form
 * Implements hook_form()
 */
function jsa_form($form, &$form_state) {

  // todo: make custom form elements required

  $jsa_obj = new Safety_Forms();
  $jsa_num = $jsa_obj->get_jsa_num();

  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Job Safety Analysis Form'),
  );

  $form['main_container']['jsa_num'] = array(
    '#type' => 'textfield',
    '#title' => t('JSA #'),
    '#default_value' => $jsa_num,
    '#disabled' => TRUE,
    '#prefix' => '<div class="jsa-num">',
    '#suffix' => '</div>',
  );

  $form['main_container']['job_task'] = array(
    '#type' => 'textfield',
    '#title' => t('Job / Task'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="job-task">',
    '#suffix' => '</div>',
  );

  $form['main_container']['page_of'] = array(
    '#type' => 'textfield',
    '#title' => t('Page Of'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="page-of">',
    '#suffix' => '</div>',
  );

  $form['main_container']['rig_num'] = array(
    '#type' => 'textfield',
    '#title' => t('Rig #'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="rig-num">',
    '#suffix' => '</div>',
  );

  $form['main_container']['supervisor'] = array(
    '#type' => 'textfield',
    '#title' => t('Supervisor'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="supervisor">',
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

  $form['main_container']['risk_cont'] = array(
    '#type' => 'container',
    '#title' => t('Risk Assessment'),
    '#tree' => TRUE,
    '#id' => 'ajax-risk-assess-cont',
    '#prefix' => '<div class="risk-cont">',
    '#suffix' => '</div>',
  );

  // $form_state['repairs_req'] to determine the number of textfields to build.
  if (empty($form_state['counter'])) {
    $form_state['counter'] = 1;
  }
  for ($i = 0; $i < $form_state['counter']; $i++) {

    $form['main_container']['risk_cont'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Risk Assessment #' . ($i + 1)),
      '#attributes' => array('class' => array('jsa-analysis-inner')),
    );

    /** Start Risk Assessment Elements */
    $form['main_container']['risk_cont'][$i]['risk_assess'] = array(
      '#type' => 'jsa_analysis',
//      '#title' => t('Risk Assessment #' . ($i + 1)),
      '#id' => 'risk_access_' . $i,
//      '#required' => TRUE,
    );

//    $form['main_container']['risk_cont'][$i]['jsa_analysis'][$i] = array(
//      '#type' => 'fieldset',
//      '#attributes' => array('class' => array('jsa-analysis-inner')),
//    );
//
//    // Add the custom elements
//    $form['main_container']['risk_cont'][$i]['jsa_analysis'][$i]['job_steps'] = array(
//      '#type' => 'textarea',
//      '#title' => t('Job Steps'),
//      //    '#required' => TRUE,
//      '#prefix' => '<div class="job-steps">',
//      '#suffix' => '</div>',
//    );

//    $form['main_container']['risk_cont'][$i]['jsa_analysis'][$i]['hazards'] = array(
//      '#type' => 'textarea',
//      '#title' => t('Hazards'),
//      //    '#required' => TRUE,
//      '#prefix' => '<div class="hazards">',
//      '#suffix' => '</div>',
//    );
//
//    $form['main_container']['risk_cont'][$i]['jsa_analysis'][$i]['risk_level'] = array(
//      '#type' => 'select',
//      '#title' => t('Risk Level'),
//      //    '#required' => TRUE,
//      '#options' => array(
//        'no_immediate_danger' => 'NO IMMEDIATE DANGER',
//        'low' => 'LOW',
//        'moderate' => 'MODERATE',
//        'high' => 'HIGH',
//      ),
//      '#prefix' => '<div class="risk-level">',
//      '#suffix' => '</div>',
//    );
//
//    $form['main_container']['risk_cont'][$i]['jsa_analysis'][$i]['steps_to_control_hazard'] = array(
//      '#type' => 'textarea',
//      '#title' => t('Steps To Control Hazard'),
//      //    '#required' => TRUE,
//      '#prefix' => '<div class="job-steps">',
//      '#suffix' => '</div>',
//    );
//
//    $form['main_container']['risk_cont'][$i]['jsa_analysis'][$i]['control_method'] = array(
//      '#type' => 'select',
//      '#title' => t('Control Method'),
//      //    '#required' => TRUE,
//      '#options' => array(
//        'engineering' => 'ENGINEERING',
//        'administration' => 'ADMINISTRATION',
//        'ppe' => 'PPE',
//      ),
//      '#prefix' => '<div class="steps-to-control-hazard">',
//      '#suffix' => '</div>',
//    );
//
//    $form['main_container']['risk_cont'][$i]['jsa_analysis'][$i]['new_risk_level'] = array(
//      '#type' => 'select',
//      '#title' => t('New Risk Level'),
//      //    '#required' => TRUE,
//      '#options' => array(
//        'no_immediate_danger' => 'NO IMMEDIATE DANGER',
//        'low' => 'LOW',
//        'moderate' => 'MODERATE',
//        'high' => 'HIGH',
//      ),
//      '#prefix' => '<div class="new-risk-level">',
//      '#suffix' => '</div>',
//    );
//
//    $form['main_container']['risk_cont'][$i]['jsa_analysis'][$i]['date_reviewed'] = array(
//      '#type' => 'textfield',
//      '#title' => t('Date JSA Reviewed'),
//      //    '#required' => TRUE,
//      '#attributes' => array('class' => array('ui-datepicker-date-reviewed')),
//      '#prefix' => '<div class="date-reviewed">',
//      '#suffix' => '</div>',
//    );
  }

  // Submit button to add more repairs text fields
  $form['main_container']['add_name'] = array(
    '#type' => 'submit',
    '#value' => 'Add Risk Assessment',
    '#submit' => array('jsa_forms_add_risk_access'),
    '#ajax' => array(
      'callback' => 'ajax_jsa_forms_callback',
      'wrapper' => 'ajax-risk-assess-cont',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#prefix' => '<div class="add-risk">',
    '#suffix' => '</div>',
  );
  // Submit button to remove repairs text fields
  $form['main_container']['remove_name'] = array(
    '#type' => 'submit',
    '#value' => 'Remove Risk Assessment',
    '#submit' => array('jsa_forms_remove_risk_assess'),
    '#ajax' => array(
      'callback' => 'ajax_jsa_forms_callback',
      'wrapper' => 'ajax-risk-assess-cont',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#prefix' => '<div class="remove-risk">',
    '#suffix' => '</div>',
  );

  $form['main_container']['weak_links'] = array(
    '#type' => 'textarea',
    '#title' => t('Weak Links (Any other unidentified issues that could cause problems)'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="weak-links">',
    '#suffix' => '</div>',
  );

  $form['main_container']['safety_items'] = array(
    '#type' => 'fieldset',
    '#title' => t('Safety Items required for job'),
    '#id' => 'jsa-review-select',
//    '#prefix' => '<div class="jsa-review-select">',
//    '#suffix' => '</div>',
  );

  $form['main_container']['safety_items']['safety_message'] = array(
    '#markup' => '<div class="user-message">PPE - All Jobs - Hard Hat, Safety Glasses, Gloves, Steel Toe Boots, Coveralls, Ear Plugs</div>',
  );

  $form['main_container']['safety_items']['jsa_review_select'] = array(
    '#type' => 'checkboxes',
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
//    '#required' => TRUE,
  );


  $form['main_container']['job_risk'] = array(
    '#type' => 'job_risk',
    '#title' => t('Required'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="job-risk">',
    '#suffix' => '</div>',
  );

  $form['main_container']['attached_photos'] = array(
    '#type' => 'radios',
    '#title' => t('Photo\'s attached for critical task'),
    '#id' => 'attached-photos',
    '#options' => array(
      'no' => 'No',
      'yes' => 'Yes',
    ),
//    '#required' => TRUE,
    '#prefix' => '<div class="attached-photos">',
    '#suffix' => '</div>',
  );

  $form['main_container']['upload_field'] = array(
    '#type' => 'container',
//    '#title' => t('Upload Images'),
    '#id' => 'upload-container',
  );


  $form['main_container']['upload_field']['upload'] = array(
    '#type' => 'plupload',
    '#title' => t('Upload Images'),
    '#description' => t('This multi-upload widget uses Plupload library.'),
    '#autoupload' => FALSE,
    '#autosubmit' => TRUE,
    '#submit_element' => '#submit-button',
    '#upload_validators' => array(
      'file_validate_extensions' => array('jpg jpeg gif png'),
//      'my_custom_file_validator' => array('some validation criteria'),
    ),
  '#plupload_settings' => array(
    'runtimes' => 'html5',
    'chunk_size' => '10mb',
    'unique_names' => TRUE,
  ),
  '#event_callbacks' => array(
//    'FilesAdded' => 'Drupal.mymodule.filesAddedCallback',
//    'UploadComplete' => 'Drupal.mymodule.uploadCompleteCallback',
  ),
);

  $form['main_container']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit JSA Form',
    '#executes_submit_callback' => TRUE,
    '#id' => 'submit-button',
    '#prefix' => '<div class="submit">',
    '#suffix' => '</div>',
  );


  return $form;
}

// Ajax function called and used to rebuild form
function ajax_jsa_forms_callback($form, &$form_state) {

  return $form['main_container']['risk_cont'];
}

/**
 * Submit handler for the "add_name" button.
 *
 * Increments the counter to add a field and causes a rebuild.
 */
function jsa_forms_add_risk_access($form, &$form_state) {

  $form_state['counter']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the "remove_name" button.
 *
 * Decrements the counter to remove a field and causes a form rebuild.
 */
function jsa_forms_remove_risk_assess($form, &$form_state) {

  if ($form_state['counter'] > 1) {
    $form_state['counter']--;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Validate JSA Form
 */
function jsa_form_validate($form, &$form_state) {
//  dsm($form_state);
  $risk_assess_data = array();

  for ($i = 0; $i < $form_state['counter']; $i++) {

    $risk_assess_data[$i]['job_steps'] = $form_state['values']['risk_cont'][$i]['risk_assess']['jsa_analysis']['job_steps'];
    $risk_assess_data[$i]['hazards'] = $form_state['values']['risk_cont'][$i]['risk_assess']['jsa_analysis']['hazards'];
    $risk_assess_data[$i]['risk_level'] = $form_state['values']['risk_cont'][$i]['risk_assess']['jsa_analysis']['risk_level'];
    $risk_assess_data[$i]['steps_to_control_hazard'] = $form_state['values']['risk_cont'][$i]['risk_assess']['jsa_analysis']['steps_to_control_hazard'];
    $risk_assess_data[$i]['control_method'] = $form_state['values']['risk_cont'][$i]['risk_assess']['jsa_analysis']['control_method'];
    $risk_assess_data[$i]['new_risk_level'] = $form_state['values']['risk_cont'][$i]['risk_assess']['jsa_analysis']['new_risk_level'];
    $risk_assess_data[$i]['date_reviewed'] = $form_state['values']['risk_cont'][$i]['risk_assess']['jsa_analysis']['date_reviewed'];
  }

  $data = array(
    'risk_assess' => $risk_assess_data,
    'job_task' => $form_state['values']['job_task'],
    'page_of' => $form_state['values']['page_of'],
    'weak_links' => $form_state['values']['weak_links'],
    'jsa_review' => $form_state['values']['jsa_review_select']['jsa_review'],
    'respirator' => $form_state['values']['jsa_review_select']['respirator'],
    'scba_saba' => $form_state['values']['jsa_review_select']['scba_saba'],
    'safety_signs' => $form_state['values']['jsa_review_select']['safety_signs'],
    'lockout' => $form_state['values']['jsa_review_select']['lockout'],
    'work_vest' => $form_state['values']['jsa_review_select']['work_vest'],
    'apron_rubber_gloves' => $form_state['values']['jsa_review_select']['apron_rubber_gloves'],
    'harness_fall_protection' => $form_state['values']['jsa_review_select']['harness_fall_protection'],
    'ventilation' => $form_state['values']['jsa_review_select']['ventilation'],
    'work_permit' => $form_state['values']['jsa_review_select']['work_permit'],
    'reflective_clothing' => $form_state['values']['jsa_review_select']['reflective_clothing'],
    'frequency' => $form_state['values']['job_risk']['jsa_risk']['frequency'],
    'possibility' => $form_state['values']['job_risk']['jsa_risk']['possibility'],
    'severity' => $form_state['values']['job_risk']['jsa_risk']['severity'],
    'maximum_rank' => $form_state['values']['job_risk']['jsa_risk']['maximum_rank'],
  );

  $form_state['jsa_form_data'] = serialize($data);
}

/**
 * Submit JSA Form
 */
function jsa_form_submit($form, &$form_state) {

  $jsa_num = $form_state['values']['jsa_num'];
  $company_fid = array();
  $image_path = array();

  if (!empty($form_state['values']['upload'])) {
    $form_state['uploaded_files'] = quotes_file_save_files($form_state['values']['upload'], $jsa_num);
  }

  // Set whether photos were attached
  $form_state['values']['attached_photos'] = !empty($form_state['values']['upload']) ?  'yes' : 'no';

  $uploaded_images = !empty($form_state['uploaded_files']) ? $form_state['uploaded_files'] : '';

  // Grab FID and URI from images object if images were uploaded
  if ($uploaded_images !== '') {
    foreach ($uploaded_images as $value) {
      $company_fid[] = $value->fid;
      $image_path[] = $value->uri;
    }
  }

  $fields = array(
    'jsa_num' => $form_state['values']['jsa_num'],
    'rig_num' => $form_state['values']['rig_num'],
    'supervisor' => $form_state['values']['supervisor'],
    'date' => $form_state['values']['date'],
    'company_image_fid' => serialize($company_fid),
    'image_path' => serialize($image_path),
    'attached_photos' => $form_state['values']['attached_photos'],
    'jsa_form_data' => $form_state['jsa_form_data'],
    'timestamp' => time(),
  );

  $query = db_insert('jsa_form')
    ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';
}

// This function saves our uploaded files
function quotes_file_save_files($files, $jsa_num) {
  $saved_files = array();

  // Returns a boolean value, TRUE if directory was successfully created
  $dir_does_exist = drupal_mkdir('public://safety_form_images/' . 'jsa_form_' . $jsa_num . '/');

  $dir = 'public://safety_form_images/' . 'jsa_form_' . $jsa_num . '/';

  foreach ($files as $uploaded_file) {
    if ($uploaded_file['status'] == 'done') {

      if($dir_does_exist) {

        $scheme = $dir; // Change to "public://" if you want to move to public files folder.

        $source = $uploaded_file['tmppath'];

        $destination = file_stream_wrapper_uri_normalize($scheme . $uploaded_file['name']);

        $destination = file_unmanaged_move($source, $destination, FILE_EXISTS_RENAME);

        $file = plupload_file_uri_to_object($destination);
        file_save($file);
        // Check the $file object to see if all necessary properties are set. Otherwise, use file_load($file->fid) to populate all of them.
        // $file = file_load($file->fid);
        $saved_files[] = $file;
      }
    }
  }

  return $saved_files;
}
