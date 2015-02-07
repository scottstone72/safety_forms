<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/working_alone_checklist_form.min.css');

/**
 * Working Alone Archive Form
 */
function working_alone_checklist_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('working_alone_checklist_form', $id);

    foreach($safety_data as $key => $val) {
      // Unserialize our data array
      $data = unserialize($val['working_alone_data']);

      $form['main_container'] = array(
        '#type' => 'fieldset',
        '#id' => 'working-alone-checklist-archive-form',
        '#title' => t("Working Alone Checklist Form ID# $id - Archived"),
      );

      $form['main_container']['date'] = array(
        '#type' => 'textfield',
        '#title' => t('Date'),
        '#value' => $val['date'],
        '#id' => 'date',
        '#disabled' => TRUE,
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
        '#value' => $data['designated_contact'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="design-contact">',
        '#suffix' => '</div>',
      );

      $form['main_container']['row1']['contact_num_1'] = array(
        '#type' => 'textfield',
        '#title' => t('Contact Number(s)'),
        '#value' => $data['contact_num_1'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="contact-num-1">',
        '#suffix' => '</div>',
      );

      $form['main_container']['row1']['contact_num_2'] = array(
        '#type' => 'textfield',
        '#title' => t('2nd #'),
        '#value' => $data['contact_num_2'],
        '#disabled' => TRUE,
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
        '#value' => $val['employee_working_alone'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="employee-working-alone">',
        '#suffix' => '</div>',
      );

      $form['main_container']['row2']['employee_num_1'] = array(
        '#type' => 'textfield',
        '#title' => t('Employee Contact Number(s)'),
        '#value' => $data['employee_num_1'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="employee-num-1">',
        '#suffix' => '</div>',
      );

      $form['main_container']['row2']['employee_num_2'] = array(
        '#type' => 'textfield',
        '#title' => t('2nd #'),
        '#value' => $data['employee_num_2'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="employee-num-2">',
        '#suffix' => '</div>',
      );


      $form['main_container']['jobs_performed'] = array(
        '#type' => 'textarea',
        '#title' => t('Job Tasks to be performed'),
        '#value' => $data['jobs_performed'],
        '#disabled' => TRUE,
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
        '#default_value' => array($data['contact_by']['cell'],$data['contact_by']['other']),
        '#disabled' => TRUE,
        '#prefix' => '<div class="contact-by">',
        '#suffix' => '</div>',
      );

      $form['main_container']['row3']['explain_other'] = array(
        '#type' => 'textarea',
        '#title' => t('Explain Other'),
        '#value' => $data['explain_other'],
        '#disabled' => TRUE,
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
        '#value' => $data['frequency_of_contact'],
        '#disabled' => TRUE,
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
        '#value' => $data['hazard_access_perform'],
        '#disabled' => TRUE,
        //    '#prefix' => '<div class="hazard-access-perform">',
        //    '#suffix' => '</div>',
      );

      $form['main_container']['row5']['under_by_employee'] = array(
        '#type' => 'checkbox',
        '#title' => t('Plan to eliminate any hazard identified or control any hazard identified developed and understood by employee?'),
        '#value' => $data['understood_by_employee'],
        '#disabled' => TRUE,
        //    '#prefix' => '<div class="under-by-employee">',
        //    '#suffix' => '</div>',
      );

      $form['main_container']['row5']['employee_trained'] = array(
        '#type' => 'checkbox',
        '#title' => t('Is Employee trained in working alone procedures?'),
        '#value' => $data['employee_trained'],
        '#disabled' => TRUE,
        //    '#prefix' => '<div class="employee-trained">',
        //    '#suffix' => '</div>',
      );

      $form['main_container']['row5']['contact_trained'] = array(
        '#type' => 'checkbox',
        '#title' => t('Has the Designated Contact person been trained in working alone procedures?'),
        '#value' => $data['contact_trained'],
        '#disabled' => TRUE,
        //    '#prefix' => '<div class="contact-trained">',
        //    '#suffix' => '</div>',
      );

      $form['main_container']['row5']['employee_assoc_risk'] = array(
        '#type' => 'checkbox',
        '#title' => t('Is the Employee aware of all the risks associated with doing the tasks involved?'),
        '#value' => $data['employee_assoc_risk'],
        '#disabled' => TRUE,
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
        '#value' => $data['employee_sign'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="employee-sign">',
        '#suffix' => '</div>',
      );

      $form['main_container']['row6']['designated_sign'] = array(
        '#type' => 'textfield',
        '#title' => t('Designated Contact'),
        '#value' => $data['designated_sign'],
        '#disabled' => TRUE,
        '#prefix' => '<div class="designated-sign">',
        '#suffix' => '</div>',
      );
    }

  $form['main_container']['link_to_safety_archive'] = array(
    '#markup' => l('Back to Safety Archive', 'safety_forms/archive', array()),
    '#prefix' => '<div class="alone-link">',
    '#suffix' => '</div>',
  );

  return $form;
}