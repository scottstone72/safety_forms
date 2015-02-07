<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/hazard_id_form.min.css');

/*
 * Hazard Id Form
 * Implements hook_form()
 */
function hazard_id_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('hazard_id_form', $id, $month = NULL, $year = NULL, $permit_num = NULL, $jsa = NULL);

  foreach($safety_data as $key => $val) {

    $hazard_id_data = unserialize($val['hazard_id_data']);
    $rules_procedures = $hazard_id_data['rules_procedures'];

    $form['main_container'] = array(
      '#type' => 'fieldset',
      '#title' => t("Hazard ID Form ID# $id - Archived"),
    );

    $form['main_container']['rig'] = array(
      '#type' => 'textfield',
      '#title' => t('Rig'),
      '#default_value' => $val['rig'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="rig">',
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

    $form['main_container']['date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date'),
      '#default_value' => $val['date'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="date">',
      '#suffix' => '</div>',
    );

    $form['main_container']['time'] = array(
      '#type' => 'textfield',
      '#title' => t('Time'),
      '#default_value' => $hazard_id_data['time'],
      '#disabled' => TRUE,
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
      '#default_value' => $val['incident_type'],
      '#disabled' => TRUE,
      '#options' => array(
        'no_compliance_at_risk' => 'Non Compliance / At Risk',
        'near_miss' => 'Near Miss',
        'hazardous_condition' => 'Hazardous Condition',
      ),
    );

    $form['main_container']['form_header']['radio_box1'] = array(
      '#type' => 'fieldset',
      '#id' => 'shutdown-normal',
      '#required' => TRUE,
    );

    $form['main_container']['form_header']['radio_box1']['shutdown_type'] = array(
      '#type' => 'radios',
      '#default_value' => $val['shutdown_type'],
      '#disabled' => TRUE,
      '#options' => array(
        'shutdown' => 'Shutdown',
        'normal' => 'Normal',
      ),
    );

    $form['main_container']['observer'] = array(
      '#type' => 'textfield',
      '#title' => t('Observer'),
      '#default_value' => $hazard_id_data['observer'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="observer">',
      '#suffix' => '</div>',
    );

    $form['main_container']['company'] = array(
      '#type' => 'textfield',
      '#title' => t('Company (If other than Bonanza)'),
      '#default_value' => $hazard_id_data['company'],
      '#disabled' => TRUE,
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
      '#default_value' => array(
        $rules_procedures['rules_procedures'],
        $rules_procedures['housekeeping'],
        $rules_procedures['tools_equip_bldg'],
        $rules_procedures['vehicle_mobile_road'],
        $rules_procedures['ppe']),
      '#disabled' => TRUE,
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
      '#default_value' => $hazard_id_data['what_you_observe'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="what-you-observe">',
      '#suffix' => '</div>',
    );

    $form['main_container']['what_action_take'] = array(
      '#type' => 'textarea',
      '#title' => t('What action did you take?'),
      '#default_value' => $hazard_id_data['what_action_take'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="what-action-take">',
      '#suffix' => '</div>',
    );
  }

  $form['main_container']['link_to_safety_archive'] = array(
    '#markup' => l('Back to Safety Archive', 'safety_forms/archive', array()),
    '#prefix' => '<div class="hazard-link">',
    '#suffix' => '</div>',
  );

  return $form;
}


