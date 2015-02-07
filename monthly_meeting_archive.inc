<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/monthly_meeting_form.min.css');

/*
 * Monthly Meeting Form
 * Implements hook_form()
 */
function monthly_meeting_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('monthly_meeting_form', $id, $month = NULL, $year = NULL, $permit_num = NULL, $jsa = NULL);

  foreach($safety_data as $key => $val) {
    // Unserialize our data array
    $data = unserialize($val['monthly_meeting_data']);

    $form['main_container'] = array(
      '#type' => 'fieldset',
      '#title' => t("Monthly Meeting Form ID# $id - Archived"),
    );

    $form['main_container']['rig'] = array(
      '#type' => 'textfield',
      '#title' => t('Rig'),
      '#default_value' => $val['rig'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="rig">',
      '#suffix' => '</div>',
    );

    $form['main_container']['job'] = array(
      '#type' => 'textfield',
      '#title' => t('Job'),
      '#default_value' => $val['job'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="job">',
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

    $form['main_container']['message'] = array(
      '#markup' => '<div class="user-message">Crew\'s alternate as Committee members.
        The Rig Managers and Committee meet in the Rig Manager\'s shack at least once every 30 days.
        The Committee exists to communicate workers health and safety concerns back to Management, make recommendations to correct
        concerns raised, and take action to correct these concerns.</div>',
    );

    $form['main_container']['outstanding_box'] = array(
      '#type' => 'fieldset',
      '#title' => t('Outstanding Concerns From Last Meeting, which was held on'),
    );

    $form['main_container']['outstanding_box']['outstanding_concerns'] = array(
      '#type' => 'textarea',
      //    '#title' => t('Concerns'),
      '#default_value' => $data['outstanding_concerns'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="outstanding-concerns">',
      '#suffix' => '</div>',
    );

    $form['main_container']['outstanding_box']['out_target_date'] = array(
      '#type' => 'textfield',
      '#title' => t('Target Date'),
      '#default_value' => $data['out_target_date'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="out-target-date">',
      '#suffix' => '</div>',
    );

    $form['main_container']['inspect_results'] = array(
      '#type' => 'fieldset',
      '#title' => t('Rig Inspection Results - Concerns Found & Corrective Action Required'),
    );

    $form['main_container']['inspect_results']['rig_inspect'] = array(
      '#type' => 'textarea',
      '#default_value' => $data['rig_inspect'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="rig-inspect">',
      '#suffix' => '</div>',
    );

    $form['main_container']['inspect_results']['rig_target_date'] = array(
      '#type' => 'textfield',
      '#title' => t('Target Date'),
      '#default_value' => $data['rig_target_date'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="rig-target-date">',
      '#suffix' => '</div>',
    );

    $form['main_container']['other_concerns'] = array(
      '#type' => 'fieldset',
      '#title' => t('Other Concerns / Topics or Suggested Improvements to Procedures or Equipment'),
    );

    $form['main_container']['other_concerns']['concerns_topics'] = array(
      '#type' => 'textarea',
      '#default_value' => $data['concerns_topics'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="concerns-topics">',
      '#suffix' => '</div>',
    );

    $form['main_container']['signatures'] = array(
      '#type' => 'fieldset',
      '#title' => t('Signatures'),
    );

    $form['main_container']['signatures']['chairman'] = array(
      '#type' => 'textfield',
      '#title' => t('Chairman'),
      '#default_value' => $data['chairman'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="chairman">',
      '#suffix' => '</div>',
    );

    $form['main_container']['signatures']['recorded_by'] = array(
      '#type' => 'textfield',
      '#title' => t('Recorded By'),
      '#default_value' => $data['recorded_by'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="recorded-by">',
      '#suffix' => '</div>',
    );

    $form['main_container']['signatures']['driller'] = array(
      '#type' => 'textfield',
      '#title' => t('Driller'),
      '#default_value' => $data['driller'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="driller">',
      '#suffix' => '</div>',
    );

    $form['main_container']['signatures']['derrick'] = array(
      '#type' => 'textfield',
      '#title' => t('Derrick'),
      '#default_value' => $data['derrick'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="derrick">',
      '#suffix' => '</div>',
    );

    $form['main_container']['signatures']['motor'] = array(
      '#type' => 'textfield',
      '#title' => t('Motor'),
      '#default_value' => $data['motor'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="motor">',
      '#suffix' => '</div>',
    );

    $form['main_container']['signatures']['floor_1'] = array(
      '#type' => 'textfield',
      '#title' => t('Floor # 1'),
      '#default_value' => $data['floor_1'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="floor-1">',
      '#suffix' => '</div>',
    );

    $form['main_container']['signatures']['floor_2'] = array(
      '#type' => 'textfield',
      '#title' => t('Floor # 2'),
      '#default_value' => $data['floor_2'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="floor-2">',
      '#suffix' => '</div>',
    );

    $form['main_container']['signatures']['rig_manager'] = array(
      '#type' => 'textfield',
      '#title' => t('Rig Manager'),
      '#default_value' => $data['rig_manager'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="rig-manager">',
      '#suffix' => '</div>',
    );

    $form['main_container']['signatures']['guests'] = array(
      '#type' => 'textarea',
      '#title' => t('Other / Guests (each name on new line)'),
      '#default_value' => $data['guests'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="guests">',
      '#suffix' => '</div>',
    );

    $form['main_container']['routing_follow_up'] = array(
      '#type' => 'fieldset',
      '#title' => t('Routing & Follow Up'),
    );

    $form['main_container']['routing_follow_up']['received_in_office'] = array(
      '#type' => 'textfield',
      '#title' => t('Received in Office'),
      '#default_value' => $val['received_in_office'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="received-in-office">',
      '#suffix' => '</div>',
    );

    $form['main_container']['routing_follow_up']['discussed'] = array(
      '#type' => 'textfield',
      '#title' => t('Discussed'),
      '#default_value' => $val['discussed'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="discussed">',
      '#suffix' => '</div>',
    );

    $form['main_container']['routing_follow_up']['assigned_to'] = array(
      '#type' => 'textfield',
      '#title' => t('Assigned To'),
      '#default_value' => $val['assigned_to'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="assigned-to">',
      '#suffix' => '</div>',
    );

    $form['main_container']['routing_follow_up']['complete_date'] = array(
      '#type' => 'textfield',
      '#title' => t('Completion Date'),
      '#default_value' => $val['complete_date'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="complete-date">',
      '#suffix' => '</div>',
    );

    $form['main_container']['routing_follow_up']['signed'] = array(
      '#type' => 'textfield',
      '#title' => t('Signed'),
      '#default_value' => $val['signed'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="signed">',
      '#suffix' => '</div>',
    );

    $form['main_container']['note_container'] = array(
      '#type' => 'fieldset',
    );

    $form['main_container']['note_container']['note'] = array(
      '#markup' => '<div class="note">
                    <li>Post Original in Doghouse & Review with other crews</li>
                    <li>2nd copy - Mail</li>
                    <li>3rd Copy - Retain in Book & Review at Start of Next Meeting</li>
                </div>',
    );
  }

  $form['main_container']['link_to_safety_archive'] = array(
    '#markup' => l('Back to Safety Archive', 'safety_forms/archive', array()),
    '#prefix' => '<div class="meeting-link">',
    '#suffix' => '</div>',
  );

  return $form;
}
