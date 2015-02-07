<?php
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/hazard_id_form.min.css');

/*
 * Hazard Id Form
 * Implements hook_form()
 */
function hazard_id_form($form, &$form_state) {

  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Hazard ID Form'),
  );

  $form['main_container']['rig'] = array(
    '#type' => 'textfield',
    '#title' => t('Rig'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="rig">',
    '#suffix' => '</div>',
  );

  $form['main_container']['location'] = array(
    '#type' => 'textfield',
    '#title' => t('Location'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="location">',
    '#suffix' => '</div>',
  );

  $form['main_container']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date'),
    '#disabled' => TRUE,
    '#default_value' => date('M d, Y'),
    '#prefix' => '<div class="date">',
    '#suffix' => '</div>',
  );

  $form['main_container']['time'] = array(
    '#type' => 'textfield',
    '#title' => t('Time'),
    '#default_value' => '',
    //    '#required' => TRUE,
    '#prefix' => '<div class="time">',
    '#suffix' => '</div>',
  );

  $form['main_container']['form_header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Condition'),
    '#required' => TRUE,
    '#id' => 'form-header',
    '#prefix' => '<div class="form-type">',
    '#suffix' => '</div>',
  );

  $form['main_container']['form_header']['incident_type'] = array(
    '#type' => 'radios',
    '#title' => t(''),
    '#options' => array(
      'no_compliance_at_risk' => 'Non Compliance / At Risk',
      'near_miss' => 'Near Miss',
      'hazardous_condition' => 'Hazardous Condition',
    ),
    //    '#required' => TRUE,
  );

  $form['main_container']['form_header']['radio_box1'] = array(
    '#type' => 'fieldset',
    '#id' => 'shutdown-normal',
    '#required' => TRUE,
  );

  $form['main_container']['form_header']['radio_box1']['shutdown_type'] = array(
    '#type' => 'radios',
//    '#title' => t(''),
    '#options' => array(
      'shutdown' => 'Shutdown',
      'normal' => 'Normal',
    ),
  );

  $form['main_container']['observer'] = array(
    '#type' => 'textfield',
    '#title' => t('Observer'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="observer">',
    '#suffix' => '</div>',
  );

  $form['main_container']['company'] = array(
    '#type' => 'textfield',
    '#title' => t('Company (If other than Bonanza)'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="company">',
    '#suffix' => '</div>',
  );

  $form['main_container']['box2'] = array(
    '#type' => 'fieldset',
    '#id' => 'rules-procedures',
    '#prefix' => '<div class="rules-procedures">',
    '#suffix' => '</div>',
  );

  $form['main_container']['box2']['procedures_cont'] = array(
    '#type' => 'checkboxes',
//    '#title' => t(''),
    '#options' => array(
      'rules_procedures' => 'Rules / Procedures',
      'housekeeping' => 'Housekeeping',
      'tools_equip_bldg' => 'Tools / Equip / Bldg',
      'vehicle_mobile_road' => 'Vehicle / Mobile Equip / Road',
      'ppe' => 'PPE',
    ),
  );

  $form['main_container']['what_you_observe'] = array(
    '#type' => 'textarea',
    '#title' => t('What did you observe?'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="what-you-observe">',
    '#suffix' => '</div>',
  );

  $form['main_container']['what_action_take'] = array(
    '#type' => 'textarea',
    '#title' => t('What action did you take?'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="what-action-take">',
    '#suffix' => '</div>',
  );

  $form['main_container']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit Hazard ID Form',
    '#executes_submit_callback' => TRUE,
    '#prefix' => '<div class="submit-button">',
    '#suffix' => '</div>',
  );


  return $form;
}

function hazard_id_form_validate($form, &$form_state) {

  $data = array(
    'time' => $form_state['values']['time'],
    'observer' => $form_state['values']['observer'],
    'company' => $form_state['values']['company'],
    'rules_procedures' => $form_state['values']['procedures_cont'],
    'what_you_observe' => $form_state['values']['what_you_observe'],
    'what_action_take' => $form_state['values']['what_action_take'],
  );

  $form_state['hazard_id_data'] = serialize($data);

}

function hazard_id_form_submit($form, &$form_state) {

  $fields = array(
    'incident_type' => $form_state['values']['incident_type'],
    'shutdown_type' => $form_state['values']['shutdown_type'],
    'rig' => $form_state['values']['rig'],
    'location' => $form_state['values']['location'],
    'hazard_id_data' => $form_state['hazard_id_data'],
    'date' => $form_state['values']['date'],
    'timestamp' => time(),
  );

  $query = db_insert('hazard_id_form')
    ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';
}