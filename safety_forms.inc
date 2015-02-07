<?php

// Load our css files
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/safety_forms_main.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/working_alone_checklist_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/monthly_meeting_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/near_miss_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/jsa_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/weekly_and_pre_job_meeting_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/hazard_id_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/erp_drills_meeting_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/work_permit_form.min.css');

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
        <div class="bkgd-image">' . l(t("Working Alone Checklist Form"), "safety_forms/working_alone_checklist_form", array('attributes' => array('class' => array('btn btn-success form-list-item ajax-link')))) . '</div>
        <div class="bkgd-image">' . l(t("Near Miss Form"), "safety_forms/near_miss_form", array('attributes' => array('class' => array('btn btn-success form-list-item ajax-link')))) . '</div>
        <div class="bkgd-image">' . l(t("Weekly and Pre-Job Meeting Form"), "safety_forms/weekly_and_pre_job_meeting_form", array('attributes' => array('class' => array('btn btn-success form-list-item ajax-link')))) . '</div>
        <div class="bkgd-image">' . l(t("Work Permit Form"), "safety_forms/work_permit_form", array('attributes' => array('class' => array('btn btn-success form-list-item ajax-link')))) . '</div>
        <div class="bkgd-image">' . l(t("Monthly Meeting Form"), "safety_forms/monthly_meeting_form", array('attributes' => array('class' => array('btn btn-success form-list-item ajax-link')))) . '</div>
        <div class="bkgd-image">' . l(t("JSA Form"), "safety_forms/jsa_form", array('attributes' => array('class' => array('btn btn-success form-list-item ajax-link')))) . '</div>
        <div class="bkgd-image">' . l(t("Hazard ID Form"), "safety_forms/hazard_id_form", array('attributes' => array('class' => array('btn btn-success form-list-item ajax-link')))) . '</div>
        <div class="bkgd-image">' . l(t("ERP Drills Meeting Form"), "safety_forms/erp_drills_meeting_form", array('attributes' => array('class' => array('btn btn-success form-list-item ajax-link')))) . '</div>
      </div>
    </div>
    <div id="content"></div>',

  );

  return $build;
}
