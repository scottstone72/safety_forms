<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/near_miss_form.min.css');

/*
 * Near Miss Archive Form
 * Implements hook_form()
 */
function near_miss_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('near_miss_form', $id, $month = NULL, $year = NULL, $permit_num = NULL, $jsa = NULL);

  foreach($safety_data as $key => $val) {

    $form['main_container'] = array(
      '#type' => 'fieldset',
      '#id' => 'near-miss-form',
      '#title' => t("Near Miss Form ID# $id - Archived"),
    );

    // Start form elements
    $form['main_container']['employee_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Employee Name'),
      '#default_value' => $val['employee_name'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="employee-name">',
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

    $form['main_container']['location'] = array(
      '#type' => 'textfield',
      '#title' => t('Location'),
      '#default_value' => $val['location'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="location">',
      '#suffix' => '</div>',
    );

    $form['main_container']['working_for'] = array(
      '#type' => 'textfield',
      '#title' => t('Working For'),
      '#default_value' => $val['working_for'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="working-for">',
      '#suffix' => '</div>',
    );

    $form['main_container']['incident_box'] = array(
      '#type' => 'fieldset',
      '#id' => 'incident-box',
    );

    $form['main_container']['incident_box']['incident'] = array(
      '#type' => 'radios',
      '#title' => t(''),
      '#default_value' => $val['incident'],
      '#options' => array(
        'hazard' => 'Hazard',
        'near_miss' => 'Near Miss',
      ),
      '#disabled' => TRUE,
    );


    $form['main_container']['description'] = array(
      '#type' => 'textarea',
      '#title' => t('Description'),
      '#default_value' => $val['description'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="description">',
      '#suffix' => '</div>',
    );

    $form['main_container']['reported_to'] = array(
      '#type' => 'textfield',
      '#title' => t('Reported To'),
      '#default_value' => $val['reported_to'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="reported-to">',
      '#suffix' => '</div>',
    );

    $form['main_container']['action_taken'] = array(
      '#type' => 'textarea',
      '#title' => t('Action Taken'),
      '#default_value' => $val['action_taken'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="action-taken">',
      '#suffix' => '</div>',
    );

    $form['main_container']['follow_up_by'] = array(
      '#type' => 'textfield',
      '#title' => t('Follow Up By'),
      '#default_value' => $val['follow_up_by'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="follow-up-by">',
      '#suffix' => '</div>',
    );

    $form['main_container']['follow_up_date'] = array(
      '#type' => 'textfield',
      '#title' => t('Follow Up Date'),
      '#default_value' => $val['follow_up_date'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="follow-up-date">',
      '#suffix' => '</div>',
    );
  }

  $form['main_container']['link_to_safety_archive'] = array(
    '#markup' => l('Back to Safety Archive', 'safety_forms/archive', array()),
    '#prefix' => '<div class="near-miss-link">',
    '#suffix' => '</div>',
  );

  return $form;
}

