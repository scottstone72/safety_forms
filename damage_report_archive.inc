<?php

require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/damage_report_form.min.css');

/**
 *
 */
function damage_report_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('damage_report_form',  $id, $month = NULL, $year = NULL, $permit_num = NULL, $jsa = NULL);

  foreach($safety_data as $key => $val) {

    $data = unserialize($val['damage_data']);

    $form['main_container'] = array(
      '#type' => 'fieldset',
      '#title' => t('Damage Report Form # ' . $id),
    );

    $form['main_container']['item_desc'] = array(
      '#type' => 'textarea',
      '#title' => t('Item Description'),
      '#default_value' => $val['item_desc'],
      '#rows' => 4,
      '#disabled' => TRUE,
      '#prefix' => '<div class="item-desc">',
      '#suffix' => '</div>',
    );

    $form['main_container']['unit_num'] = array(
      '#type' => 'textfield',
      '#title' => t('Unit #'),
      '#default_value' => $val['unit_num'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="unit-num">',
      '#suffix' => '</div>',
    );

    $form['main_container']['date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date Damage Noticed'),
      '#default_value' => $val['date'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="date-damage-noticed">',
      '#suffix' => '</div>',
    );

    $form['main_container']['damage_noted_by'] = array(
      '#type' => 'textfield',
      '#title' => t('Damage Noticed By'),
      '#default_value' => $val['damage_noted_by'],
      '#disabled' => TRUE,
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

    foreach ($data as $k => $v) {

      $form['main_container']['damage_cont']['damage_inner_cont'][$k] = array(
        '#type' => 'fieldset',
        '#prefix' => '<div class="damage-inner-cont">',
        '#suffix' => '</div>',
      );


      $form['main_container']['damage_cont']['damage_inner_cont'][$k]['noted_damages'] = array(
        '#type' => 'textarea',
        '#title' => t('Damage #' . ($k + 1)),
        '#rows' => 2,
        '#default_value' => $v['noted_damages'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="noted-damages">',
        '#suffix' => '</div>',
      );

      $form['main_container']['damage_cont']['damage_inner_cont'][$k]['damage_qty'] = array(
        '#type' => 'textfield',
        '#title' => t('Qty'),
        '#default_value' => $v['damage_qty'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="est-repair-costs">',
        '#suffix' => '</div>',
      );

      $form['main_container']['damage_cont']['damage_inner_cont'][$k]['damage_unit_cost'] = array(
        '#type' => 'textfield',
        '#title' => t('Unit Cost'),
        '#default_value' => $v['damage_unit_cost'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="unit-cost">',
        '#suffix' => '</div>',
      );

      $form['main_container']['damage_cont']['damage_inner_cont'][$k]['damage_total_cost'] = array(
        '#type' => 'textfield',
        '#title' => t('Total Cost'),
        '#default_value' => $v['damage_total_cost'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="total-cost">',
        '#suffix' => '</div>',
      );

      $form['main_container']['damage_cont']['damage_inner_cont'][$k]['labor'] = array(
        '#type' => 'textarea',
        '#title' => t('Labor #' . ($k + 1)),
        '#rows' => 2,
        '#default_value' => $v['labor'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="labor">',
        '#suffix' => '</div>',
      );

      $form['main_container']['damage_cont']['damage_inner_cont'][$k]['labor_qty'] = array(
        '#type' => 'textfield',
        '#title' => t('Qty'),
        '#default_value' => $v['labor_qty'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="est-repair-costs">',
        '#suffix' => '</div>',
      );

      $form['main_container']['damage_cont']['damage_inner_cont'][$k]['labor_unit_cost'] = array(
        '#type' => 'textfield',
        '#title' => t('Unit Cost'),
        '#default_value' => $v['labor_unit_cost'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="unit-cost">',
        '#suffix' => '</div>',
      );

      $form['main_container']['damage_cont']['damage_inner_cont'][$k]['labor_total_cost'] = array(
        '#type' => 'textfield',
        '#title' => t('Total Cost'),
        '#default_value' => $v['labor_total_cost'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="total-cost">',
        '#suffix' => '</div>',
      );
    }


    $form['main_container']['total_repair_cost'] = array(
      '#type' => 'textfield',
      '#title' => t('Total Estimated Repair Cost'),
      '#default_value' => $val['total_repair_cost'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="total-est-repair-cost">',
      '#suffix' => '</div>',
    );

    $form['main_container']['company_rep_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Company Rep - Name'),
      '#default_value' => $val['company_rep_name'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="company-rep-name">',
      '#suffix' => '</div>',
    );

    $form['main_container']['company_rep_signature'] = array(
      '#type' => 'textfield',
      '#title' => t('Company Rep - Signature'),
      '#default_value' => $val['company_rep_signature'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="company-rep-signature">',
      '#suffix' => '</div>',
    );

    $form['main_container']['ponderosa_rep_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Ponderosa Rep - Name'),
      '#default_value' => $val['ponderosa_rep_name'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="ponderosa-rep-name">',
      '#suffix' => '</div>',
    );

    $form['main_container']['ponderosa_rep_signature'] = array(
      '#type' => 'textfield',
      '#title' => t('Ponderosa Rep - Signature'),
      '#default_value' => $val['ponderosa_rep_signature'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="ponderosa-rep-signature">',
      '#suffix' => '</div>',
    );

  }

  return $form;
}
