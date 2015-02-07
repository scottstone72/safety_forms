<?php
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/near_miss_form.min.css');
drupal_add_js(drupal_get_path('module', 'safety_forms') . '/dist/js/safety_forms_ajax_get_form.min.js');

/*
 * Near Miss Form
 * Implements hook_form()
 */
function near_miss_form($form, &$form_state) {

  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Near Miss Form'),
  );

  // Start form elements
  $form['main_container']['employee_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Employee Name'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="employee-name">',
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

  $form['main_container']['working_for'] = array(
    '#type' => 'textfield',
    '#title' => t('Working For'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="working-for">',
    '#suffix' => '</div>',
  );

  $form['main_container']['incident_box'] = array(
    '#type' => 'fieldset',
    '#id' => 'incident-box',
  );

  $form['main_container']['incident_box']['incident'] = array(
    '#type' => 'radios',
    '#title' => t('Incident Type'),
    '#options' => array(
      'hazard' => 'Hazard',
      'near_miss' => 'Near Miss',
    ),
    '#required' => TRUE,
  );


  $form['main_container']['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="description">',
    '#suffix' => '</div>',
  );

  $form['main_container']['reported_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Reported To'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="reported-to">',
    '#suffix' => '</div>',
  );

  $form['main_container']['action_taken'] = array(
    '#type' => 'textarea',
    '#title' => t('Action Taken'),
    '#default_value' => '',
    '#prefix' => '<div class="action-taken">',
    '#suffix' => '</div>',
  );

  $form['main_container']['follow_up_by'] = array(
    '#type' => 'textfield',
    '#title' => t('Follow Up By'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="follow-up-by">',
    '#suffix' => '</div>',
  );

  $form['main_container']['follow_up_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Follow Up Date'),
    '#attributes' => array('class' => array('ui-datepicker-follow')),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="follow-up-date">',
    '#suffix' => '</div>',
  );


  $form['main_container']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit Near Miss Form',
    '#executes_submit_callback' => TRUE,
    '#prefix' => '<div class="submit-button">',
    '#suffix' => '</div>',
  );


  return $form;
}

function near_miss_form_submit($form, &$form_state) {

  $fields = array(
      'employee_name' => $form_state['values']['employee_name'],
      'date' => $form_state['values']['date'],
      'location' => $form_state['values']['location'],
      'working_for' => $form_state['values']['working_for'],
      'incident' => $form_state['values']['incident'],
//      'hazard' => $form_state['values']['incident']['hazard'],
//      'near_miss' => $form_state['values']['incident']['near_miss'],
      'description' => $form_state['values']['description'],
      'reported_to' => $form_state['values']['reported_to'],
      'action_taken' => $form_state['values']['action_taken'],
      'follow_up_by' => $form_state['values']['follow_up_by'],
      'follow_up_date' => $form_state['values']['follow_up_date'],
      'timestamp' => time(),
  );

  $query = db_insert('near_miss_form')
    ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';
}