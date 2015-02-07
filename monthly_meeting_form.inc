<?php
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/monthly_meeting_form.min.css');
// Load our javascript files
drupal_add_js(drupal_get_path('module', 'safety_forms') . '/dist/js/safety_forms_ajax_get_form.min.js');

/*
 * Monthly Meeting Form
 * Implements hook_form()
 */
function monthly_meeting_form($form, &$form_state) {

  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Monthly Meeting Form'),
  );

  $form['main_container']['rig'] = array(
    '#type' => 'textfield',
    '#title' => t('Rig'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="rig">',
    '#suffix' => '</div>',
  );

  $form['main_container']['job'] = array(
    '#type' => 'textfield',
    '#title' => t('Job'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="job">',
    '#suffix' => '</div>',
  );

  $form['main_container']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date'),
    '#default_value' => date('M d, Y'),
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
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="outstanding-concerns">',
    '#suffix' => '</div>',
  );

  $form['main_container']['outstanding_box']['out_target_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Target Date'),
    '#default_value' => '',
    '#attributes' => array('class' => array('ui-datepicker')),
    '#required' => TRUE,
    '#prefix' => '<div class="out-target-date">',
    '#suffix' => '</div>',
  );

  $form['main_container']['inspect_results'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rig Inspection Results - Concerns Found & Corrective Action Required'),
  );

  $form['main_container']['inspect_results']['rig_inspect'] = array(
    '#type' => 'textarea',
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="rig-inspect">',
    '#suffix' => '</div>',
  );

  $form['main_container']['inspect_results']['rig_target_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Target Date'),
    '#default_value' => '',
    '#attributes' => array('class' => array('ui-datepicker')),
    '#required' => TRUE,
    '#prefix' => '<div class="rig-target-date">',
    '#suffix' => '</div>',
  );

  $form['main_container']['other_concerns'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other Concerns / Topics or Suggested Improvements to Procedures or Equipment'),
  );

  $form['main_container']['other_concerns']['concerns_topics'] = array(
    '#type' => 'textarea',
    '#default_value' => '',
    '#required' => TRUE,
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
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="chairman">',
    '#suffix' => '</div>',
  );

  $form['main_container']['signatures']['recorded_by'] = array(
    '#type' => 'textfield',
    '#title' => t('Recorded By'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="recorded-by">',
    '#suffix' => '</div>',
  );

  $form['main_container']['signatures']['driller'] = array(
    '#type' => 'textfield',
    '#title' => t('Driller'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="driller">',
    '#suffix' => '</div>',
  );

  $form['main_container']['signatures']['derrick'] = array(
    '#type' => 'textfield',
    '#title' => t('Derrick'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="derrick">',
    '#suffix' => '</div>',
  );

  $form['main_container']['signatures']['motor'] = array(
    '#type' => 'textfield',
    '#title' => t('Motor'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="motor">',
    '#suffix' => '</div>',
  );

  $form['main_container']['signatures']['floor_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Floor # 1'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="floor-1">',
    '#suffix' => '</div>',
  );

  $form['main_container']['signatures']['floor_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Floor # 2'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="floor-2">',
    '#suffix' => '</div>',
  );

  $form['main_container']['signatures']['rig_manager'] = array(
    '#type' => 'textfield',
    '#title' => t('Rig Manager'),
    '#default_value' => '',
//    '#required' => TRUE,
    '#prefix' => '<div class="rig-manager">',
    '#suffix' => '</div>',
  );

  $form['main_container']['signatures']['guests'] = array(
    '#type' => 'textarea',
    '#title' => t('Other / Guests (each name on new line)'),
    '#default_value' => '',
//    '#required' => TRUE,
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
    '#default_value' => '',
    '#attributes' => array('class' => array('ui-datepicker-received')),
    '#required' => TRUE,
    '#prefix' => '<div class="received-in-office">',
    '#suffix' => '</div>',
  );

  $form['main_container']['routing_follow_up']['discussed'] = array(
    '#type' => 'textfield',
    '#title' => t('Discussed'),
    '#default_value' => '',
    '#attributes' => array('class' => array('ui-datepicker-discussed')),
    '#required' => TRUE,
    '#prefix' => '<div class="discussed">',
    '#suffix' => '</div>',
  );

  $form['main_container']['routing_follow_up']['assigned_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Assigned To'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="assigned-to">',
    '#suffix' => '</div>',
  );

  $form['main_container']['routing_follow_up']['complete_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Completion Date'),
    '#default_value' => '',
    '#attributes' => array('class' => array('ui-datepicker-complete')),
    '#required' => TRUE,
    '#prefix' => '<div class="complete-date">',
    '#suffix' => '</div>',
  );

  $form['main_container']['routing_follow_up']['signed'] = array(
    '#type' => 'textfield',
    '#title' => t('Signed'),
    '#default_value' => '',
    '#required' => TRUE,
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

  $form['main_container']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit Monthly Meeting Form',
    '#executes_submit_callback' => TRUE,
    '#prefix' => '<div class="submit-button">',
    '#suffix' => '</div>',
  );


  return $form;
}

function monthly_meeting_form_validate($form, &$form_state) {

  $data = array(
    'outstanding_concerns' => $form_state['values']['outstanding_concerns'],
    'out_target_date' => $form_state['values']['out_target_date'],
    'rig_inspect' => $form_state['values']['rig_inspect'],
    'rig_target_date' => $form_state['values']['rig_target_date'],
    'concerns_topics' => $form_state['values']['concerns_topics'],
    'chairman' => $form_state['values']['chairman'],
    'recorded_by' => $form_state['values']['recorded_by'],
    'driller' => $form_state['values']['driller'],
    'derrick' => $form_state['values']['derrick'],
    'motor' => $form_state['values']['motor'],
    'floor_1' => $form_state['values']['floor_1'],
    'floor_2' => $form_state['values']['floor_2'],
    'rig_manager' => $form_state['values']['rig_manager'],
    'guests' => $form_state['values']['guests'],
  );

  $form_state['monthly_meeting_data'] = serialize($data);
}


function monthly_meeting_form_submit($form, &$form_state) {

  $fields = array(
    'rig' => $form_state['values']['rig'],
    'job' => $form_state['values']['job'],
    'date' => $form_state['values']['date'],
    'received_in_office' => $form_state['values']['received_in_office'],
    'discussed' => $form_state['values']['discussed'],
    'assigned_to' => $form_state['values']['assigned_to'],
    'complete_date' => $form_state['values']['complete_date'],
    'signed' => $form_state['values']['signed'],
    'monthly_meeting_data' => $form_state['monthly_meeting_data'],
    'timestamp' => time(),
  );

//  dsm($fields);
  $query = db_insert('monthly_meeting_form')
    ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';
}