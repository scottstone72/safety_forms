<?php
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/working_alone_checklist_form.min.css');

/*
 * Working Alone Form
 * Implements hook_form()
 */
function working_alone_checklist_form($form, &$form_state) {

  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#id' => 'main-container',
    '#title' => t('Working Alone Checklist '),
  );

  $form['main_container']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date'),
    '#default_value' => date('M d, Y'),
    '#id' => 'date',
    '#prefix' => '<div class="date">',
    '#suffix' => '</div>',
  );


  $form['main_container']['row1'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('row')),
  );

  // Start form elements
  $form['main_container']['row1']['designated_contact'] = array(
    '#type' => 'textfield',
    '#title' => t('Designated Contact'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="design-contact">',
    '#suffix' => '</div>',
  );

  $form['main_container']['row1']['contact_num_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Contact Number(s)'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="contact-num-1">',
    '#suffix' => '</div>',
  );

  $form['main_container']['row1']['contact_num_2'] = array(
    '#type' => 'textfield',
    '#title' => t('2nd #'),
    '#default_value' => '',
    '#prefix' => '<div class="contact-num-2">',
    '#suffix' => '</div>',
  );

  $form['main_container']['row2'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('row')),
  );

  $form['main_container']['row2']['employee_working_alone'] = array(
    '#type' => 'textfield',
    '#title' => t('Employee who will be working alone'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="employee-working-alone">',
    '#suffix' => '</div>',
  );

  $form['main_container']['row2']['employee_num_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Employee Contact Number(s)'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="employee-num-1">',
    '#suffix' => '</div>',
  );
  
  $form['main_container']['row2']['employee_num_2'] = array(
    '#type' => 'textfield',
    '#title' => t('2nd #'),
    '#default_value' => '',
    '#prefix' => '<div class="employee-num-2">',
    '#suffix' => '</div>',
  );


  $form['main_container']['jobs_performed'] = array(
    '#type' => 'textarea',
    '#title' => t('Job Tasks to be performed'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="jobs-performed">',
    '#suffix' => '</div>',
  );

  $form['main_container']['row3'] = array(
    '#type' => 'fieldset',
//    '#attributes' => array('class' => array('row row3')),
  );

  $form['main_container']['row3']['contact_by'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Contact to Employee will be made by'),
    '#options' => array(
      'cell' => 'Cell',
      'other' => 'Other',
    ),
    '#required' => TRUE,
    '#prefix' => '<div class="contact-by">',
    '#suffix' => '</div>',
  );

  $form['main_container']['row3']['explain_other'] = array(
    '#type' => 'textarea',
    '#title' => t('Explain Other'),
    '#default_value' => '',
    '#prefix' => '<div class="explain-other">',
    '#suffix' => '</div>',
  );

  $form['main_container']['row4'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('row')),
  );

  $form['main_container']['row4']['frequency_of_contact'] = array(
    '#type' => 'textfield',
    '#title' => t('Frequency of Employee contact'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="frequency-of-contact">',
    '#suffix' => '</div>',
  );

  $form['main_container']['row5'] = array(
    '#type' => 'fieldset',
    '#attributes' => array('class' => array('hazard-container')),
  );

  $form['main_container']['row5']['hazard_access_perform'] = array(
    '#type' => 'checkbox',
    '#title' => t('Has a Hazard Assessment been performed?'),
    '#default_value' => '',
    '#required' => TRUE,
//    '#prefix' => '<div class="hazard-access-perform">',
//    '#suffix' => '</div>',
  );

  $form['main_container']['row5']['under_by_employee'] = array(
    '#type' => 'checkbox',
    '#title' => t('Plan to eliminate any hazard identified or control any hazard identified developed and understood by employee?'),
    '#default_value' => '',
    '#required' => TRUE,
//    '#prefix' => '<div class="under-by-employee">',
//    '#suffix' => '</div>',
  );

  $form['main_container']['row5']['employee_trained'] = array(
    '#type' => 'checkbox',
    '#title' => t('Is Employee trained in working alone procedures?'),
    '#default_value' => '',
    '#required' => TRUE,
//    '#prefix' => '<div class="employee-trained">',
//    '#suffix' => '</div>',
  );

  $form['main_container']['row5']['contact_trained'] = array(
    '#type' => 'checkbox',
    '#title' => t('Has the Designated Contact person been trained in working alone procedures?'),
    '#default_value' => '',
    '#required' => TRUE,
//    '#prefix' => '<div class="contact-trained">',
//    '#suffix' => '</div>',
  );

  $form['main_container']['row5']['employee_assoc_risk'] = array(
    '#type' => 'checkbox',
    '#title' => t('Is the Employee aware of all the risks associated with doing the tasks involved?'),
    '#default_value' => '',
    '#required' => TRUE,
//    '#prefix' => '<div class="employee-assoc-risk">',
//    '#suffix' => '</div>',
  );

  $form['main_container']['row6'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('row')),
  );

  $form['main_container']['row6']['employee_sign'] = array(
    '#type' => 'textfield',
    '#title' => t('Employee Working Alone'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="employee-sign">',
    '#suffix' => '</div>',
  );

  $form['main_container']['row6']['designated_sign'] = array(
    '#type' => 'textfield',
    '#title' => t('Designated Contact'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="designated-sign">',
    '#suffix' => '</div>',
  );

  $form['main_container']['submit'] = array(
    '#type' => 'submit',
    '#title' => t(''),
    '#value' => 'Submit Working Alone Form',
//    '#executes_submit_callback' => TRUE,
    '#prefix' => '<div class="submit-button">',
    '#suffix' => '</div>',
//    '#ajax' => array(
//      'callback' => 'working_alone_checklist_form_submit'
//    ),
  );


  return $form;
}

function working_alone_checklist_form_validate($form, &$form_state) {

  $data = array(
    'designated_contact' => $form_state['values']['designated_contact'],
    'contact_num_1' => $form_state['values']['contact_num_1'],
    'contact_num_2' => $form_state['values']['contact_num_2'],
    'employee_num_1' => $form_state['values']['employee_num_1'],
    'employee_num_2' => $form_state['values']['employee_num_2'],
    'jobs_performed' => $form_state['values']['jobs_performed'],
    'contact_by' => $form_state['values']['contact_by'],
    'explain_other' => $form_state['values']['explain_other'],
    'frequency_of_contact' => $form_state['values']['frequency_of_contact'],
    'hazard_access_perform' => $form_state['values']['hazard_access_perform'],
    'understood_by_employee' => $form_state['values']['under_by_employee'],
    'employee_trained' => $form_state['values']['employee_trained'],
    'contact_trained' => $form_state['values']['contact_trained'],
    'employee_assoc_risk' => $form_state['values']['employee_assoc_risk'],
    'employee_sign' => $form_state['values']['employee_sign'],
    'designated_sign' => $form_state['values']['designated_sign'],
  );

  $form_state['serialized_data'] = serialize($data);

}

function working_alone_checklist_form_submit($form, &$form_state) {

  $fields = array(
    'date' => $form_state['values']['date'],
    'employee_working_alone' => $form_state['values']['employee_working_alone'],
    'working_alone_data' => $form_state['serialized_data'],
    'timestamp' => time(),
  );

//  dsm($fields);

  $query = db_insert('working_alone_checklist_form')
            ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }
  $form_state['redirect'] = 'safety_forms';
}