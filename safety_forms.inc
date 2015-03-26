<?php

// Load our css files
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/safety_forms_main.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/working_alone_checklist_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/monthly_meeting_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/near_miss_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/jsa_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/weekly_and_pre_job_meeting_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/hazard_id_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/erp_drills_meeting_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/work_permit_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/daily_crane_pre_op_checklist_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/damage_report_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/monthly_vehicle_inspection_report_form.min.css');
//drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/shop_and_yard_inspection_form.min.css');

/**
 *  Main Safety Forms Page
 */
function safety_forms_page() {

  $build = array();

  $build['form_links'] = array(
    '#type' => 'markup',
    '#markup' => '<div class="row">
      <h2 id="load-form-text">Select button to load a form</h2>
      <div class="form-list">
        <div class="bkgd-image">' . l(t("Working Alone Checklist Form"), "safety_forms/working_alone_checklist_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("Near Miss Form"), "safety_forms/near_miss_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("Weekly and Pre-Job Meeting Form"), "safety_forms/weekly_and_pre_job_meeting_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("Work Permit Form"), "safety_forms/work_permit_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("Monthly Meeting Form"), "safety_forms/monthly_meeting_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("JSA Form"), "safety_forms/jsa_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("Hazard ID Form"), "safety_forms/hazard_id_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("ERP Drills Meeting Form"), "safety_forms/erp_drills_meeting_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("Daily Crane Pre-Op Checklist Form"), "safety_forms/daily_crane_pre_op_checklist_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("Damage Report Form"), "safety_forms/damage_report_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("Monthly Vehicle Inspection Form"), "safety_forms/monthly_vehicle_inspection_report_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
        <div class="bkgd-image">' . l(t("Shop and Yard Inspection Form"), "safety_forms/shop_and_yard_inspection_form", array('attributes' => array('class' => array('btn btn-success form-list-item')))) . '</div>
      </div>
    </div>
    <div id="content"></div>',

  );

  return $build;
}
