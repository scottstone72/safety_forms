<?php

drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/damage_report_form.min.css');

/**
 *
 */
function damage_report_form($form, &$form_state) {

  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Damage Report Form'),
  );

  $form['main_container']['item_desc'] = array(
    '#type' => 'textarea',
    '#title' => t('Item Description'),
    '#default_value' => '',
    '#rows' => 4,
//    '#required' => TRUE,
    '#prefix' => '<div class="item-desc">',
    '#suffix' => '</div>',
  );

  $form['main_container']['unit_num'] = array(
    '#type' => 'textfield',
    '#title' => t('Unit #'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="unit-num">',
    '#suffix' => '</div>',
  );

  $form['main_container']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date Damage Noticed'),
    '#default_value' => date('M d, Y'),
//    '#required' => TRUE,
    '#prefix' => '<div class="date-damage-noticed">',
    '#suffix' => '</div>',
  );

  $form['main_container']['damage_noted_by'] = array(
    '#type' => 'textfield',
    '#title' => t('Damage Noticed By'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="damage-noted-by">',
    '#suffix' => '</div>',
  );

  $form['main_container']['damage_cont'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => t('Noted Damages and Repair Costs'),
    '#id' => 'ajax-damage-report-cont',
    '#prefix' => '<div class="damage-cont">',
    '#suffix' => '</div>',
  );

  // $form_state['repairs_req'] to determine the number of textfields to build.
  if (empty($form_state['counter'])) {
    $form_state['counter'] = 1;
  }
  for ($i = 0; $i < $form_state['counter']; $i++) {


    $form['main_container']['damage_cont']['damage_inner_cont'][$i] = array(
      '#type' => 'fieldset',
      '#prefix' => '<div class="damage-inner-cont">',
      '#suffix' => '</div>',
    );


    $form['main_container']['damage_cont']['damage_inner_cont'][$i]['noted_damages'] = array(
      '#type' => 'textarea',
      '#title' => t('Damage #' . ($i + 1)),
      '#rows' => 2,
      '#default_value' => '',
//      '#required' => TRUE,
      '#prefix' => '<div class="noted-damages">',
      '#suffix' => '</div>',
    );

    $form['main_container']['damage_cont']['damage_inner_cont'][$i]['damage_qty'] = array(
      '#type' => 'textfield',
      '#title' => t('Qty'),
      '#default_value' => '',
//      '#required' => TRUE,
      '#prefix' => '<div class="est-repair-costs">',
      '#suffix' => '</div>',
    );

    $form['main_container']['damage_cont']['damage_inner_cont'][$i]['damage_unit_cost'] = array(
      '#type' => 'textfield',
      '#title' => t('Unit Cost'),
      '#default_value' => '',
//      '#required' => TRUE,
      '#prefix' => '<div class="unit-cost">',
      '#suffix' => '</div>',
    );

    $form['main_container']['damage_cont']['damage_inner_cont'][$i]['damage_total_cost'] = array(
      '#type' => 'textfield',
      '#title' => t('Total Cost'),
      '#default_value' => '',
//      '#required' => TRUE,
      '#prefix' => '<div class="total-cost">',
      '#suffix' => '</div>',
    );

    $form['main_container']['damage_cont']['damage_inner_cont'][$i]['labor'] = array(
      '#type' => 'textarea',
      '#title' => t('Labor #' . ($i + 1)),
      '#rows' => 2,
      '#default_value' => '',
//      '#required' => TRUE,
      '#prefix' => '<div class="labor">',
      '#suffix' => '</div>',
    );

    $form['main_container']['damage_cont']['damage_inner_cont'][$i]['labor_qty'] = array(
      '#type' => 'textfield',
      '#title' => t('Qty'),
      '#default_value' => '',
//      '#required' => TRUE,
      '#prefix' => '<div class="est-repair-costs">',
      '#suffix' => '</div>',
    );

    $form['main_container']['damage_cont']['damage_inner_cont'][$i]['labor_unit_cost'] = array(
      '#type' => 'textfield',
      '#title' => t('Unit Cost'),
      '#default_value' => '',
//      '#required' => TRUE,
      '#prefix' => '<div class="unit-cost">',
      '#suffix' => '</div>',
    );

    $form['main_container']['damage_cont']['damage_inner_cont'][$i]['labor_total_cost'] = array(
      '#type' => 'textfield',
      '#title' => t('Total Cost'),
      '#default_value' => '',
//      '#required' => TRUE,
      '#prefix' => '<div class="total-cost">',
      '#suffix' => '</div>',
    );
  }

  // Submit button to add more repairs text fields
  $form['main_container']['damage_cont']['add_name'] = array(
    '#type' => 'submit',
    '#value' => 'Add Noted Damage',
    '#submit' => array('damage_report_forms_add_damage'),
    '#ajax' => array(
      'callback' => 'ajax_damage_report_callback',
      'wrapper' => 'ajax-damage-report-cont',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#prefix' => '<div class="add-damage">',
    '#suffix' => '</div>',
  );

  // Submit button to remove repairs text fields
  $form['main_container']['damage_cont']['remove_name'] = array(
    '#type' => 'submit',
    '#value' => 'Remove Noted Damage',
    '#submit' => array('damage_report_forms_remove_damage'),
    '#ajax' => array(
      'callback' => 'ajax_damage_report_callback',
      'wrapper' => 'ajax-damage-report-cont',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#prefix' => '<div class="remove-damage">',
    '#suffix' => '</div>',
  );

  $form['main_container']['total_repair_cost'] = array(
    '#type' => 'textfield',
    '#title' => t('Total Estimated Repair Cost'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="total-est-repair-cost">',
    '#suffix' => '</div>',
  );

  $form['main_container']['company_rep_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Company Rep - Name'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="company-rep-name">',
    '#suffix' => '</div>',
  );

  $form['main_container']['company_rep_signature'] = array(
    '#type' => 'textfield',
    '#title' => t('Company Rep - Signature'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="company-rep-signature">',
    '#suffix' => '</div>',
  );

  $form['main_container']['ponderosa_rep_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Ponderosa Rep - Name'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="ponderosa-rep-name">',
    '#suffix' => '</div>',
  );

  $form['main_container']['ponderosa_rep_signature'] = array(
    '#type' => 'textfield',
    '#title' => t('Ponderosa Rep - Signature'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="ponderosa-rep-signature">',
    '#suffix' => '</div>',
  );

  $form['main_container']['submit_button'] = array(
    '#type' => 'submit',
    '#value' => 'Submit Damage Report Form',
    '#prefix' => '<div class="submit-button">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Validate damage_report_form
 */
function damage_report_form_validate($form, &$form_state) {

  $data = array();
  for ($i = 0; $i < $form_state['counter']; $i++) {

    $data[] = $form_state['values']['damage_cont']['damage_inner_cont'][$i];
  }

  $form_state['values']['damage_data'] = serialize($data);
}

/**
 * Validate damage_report_form
 */
function damage_report_form_submit($form, &$form_state) {

  $fields = array(
    'item_desc' => $form_state['values']['item_desc'],
    'unit_num' => $form_state['values']['unit_num'],
    'date' => $form_state['values']['date'],
    'damage_noted_by' => $form_state['values']['damage_noted_by'],
    'damage_data' => $form_state['values']['damage_data'],
    'total_repair_cost' => $form_state['values']['total_repair_cost'],
    'company_rep_name' => $form_state['values']['company_rep_name'],
    'company_rep_signature' => $form_state['values']['company_rep_signature'],
    'ponderosa_rep_name' => $form_state['values']['ponderosa_rep_name'],
    'ponderosa_rep_signature' => $form_state['values']['ponderosa_rep_signature'],
    'timestamp' => time(),
  );

  $query = db_insert('damage_report_form')
    ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';

}


// Ajax function called and used to rebuild form
function ajax_damage_report_callback($form, &$form_state) {

  return $form['main_container']['damage_cont'];
}

/**
 * Submit handler for the "add_name" button.
 *
 * Increments the counter to add a field and causes a rebuild.
 */
function damage_report_forms_add_damage($form, &$form_state) {

  $form_state['counter']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the "remove_name" button.
 *
 * Decrements the counter to remove a field and causes a form rebuild.
 */
function damage_report_forms_remove_damage($form, &$form_state) {

  if ($form_state['counter'] > 1) {
    $form_state['counter']--;
  }
  $form_state['rebuild'] = TRUE;
}