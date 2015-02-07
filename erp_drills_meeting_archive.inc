<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/erp_drills_meeting_form.min.css');

/*
 * ERP Drills Meeting Form
 * Implements hook_form()
 */
function erp_drills_meeting_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('erp_drills_meeting_form', $id, $month = NULL, $year = NULL, $permit_num = NULL, $jsa = NULL);

  foreach($safety_data as $key => $val) {

    $erp_form_data = unserialize($val['erp_form_data']); // Unserialize our data array

    $form['main_container'] = array(
      '#type' => 'fieldset',
      '#title' => t("ERP Drills Meeting Form ID# $id - Archived"),
    );

    $form['main_container']['message'] = array(
      '#markup' => '<div class="user-message">Drills are regularly held to ensure everyone has a clear understanding of what to do in the
                    event of an emergency. Drills can either be a discussion where the event is reviewed
                    or an actual role play where takes part in the drill.</div>',
    );

    $form['main_container']['form_body'] = array(
      '#type' => 'fieldset',
    );

    // Start form elements
    $form['main_container']['form_body']['date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date'),
      '#default_value' => $val['date'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="date">',
      '#suffix' => '</div>',
    );

    $form['main_container']['form_body']['recorded_by'] = array(
      '#type' => 'textfield',
      '#title' => t('Recorded By'),
      '#default_value' => $val['recorded_by'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="recorded-by">',
      '#suffix' => '</div>'
    );

    $form['main_container']['form_body']['box'] = array(
      '#type' => 'fieldset',
      '#title' => t('Choose Drill'),
      '#attributes' => array('class' => array('box')),
    );

    $form['main_container']['form_body']['box']['drill_type'] = array(
      '#type' => 'radios',
      '#title' => t(''),
      '#default_value' => $val['drill_type'],
      '#disabled' => TRUE,
      '#options' => array(
        'bop_drill' => 'BOP Drill',
        'man_down' => 'Man Down',
        'confined_space' => 'Confined Space',
        'h2s' => 'H2S',
        'fire' => 'Fire',
        'evacuation' => 'Evacuation',
        'high_angle_rescue' => 'High Angle Rescue',
        'natural_disaster' => 'Natural Disaster',
      ),
    );

    $form['main_container']['form_body']['attendance'] = array(
      '#type' => 'textarea',
      '#title' => t('Attendance (sign name) (each name on new line)'),
      '#default_value' => $erp_form_data['attendance'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="attendance">',
      '#suffix' => '</div>'
    );


    $form['main_container']['form_body']['summary_of_drills'] = array(
      '#type' => 'textarea',
      '#title' => t('Summary Of Drill(s) performed'),
      '#default_value' => $erp_form_data['summary_of_drills'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="summary-of-drills">',
      '#suffix' => '</div>',
    );

    $form['main_container']['form_body']['hazard_review'] = array(
      '#type' => 'textarea',
      '#title' => t('Hazard Review'),
      '#default_value' => $erp_form_data['hazard_review'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="hazard-review">',
      '#suffix' => '</div>',
    );


    $form['main_container']['form_body']['other'] = array(
      '#type' => 'textarea',
      '#title' => t('Other'),
      '#default_value' => $erp_form_data['other'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="other">',
      '#suffix' => '</div>',
    );
  }

  $form['main_container']['link_to_safeety_archive'] = array(
    '#markup' => l('Back to Safety Archive', 'safety_forms/archive', array()),
    '#prefix' => '<div class="erp-link">',
    '#suffix' => '</div>',
  );

  return $form;
}