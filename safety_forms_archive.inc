<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');
// Load our css files
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/safety_forms_archive.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/working_alone_checklist_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/monthly_meeting_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/near_miss_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/jsa_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/weekly_and_pre_job_meeting_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/hazard_id_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/erp_drills_meeting_form.min.css');
drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/work_permit_form.min.css');


/**
 * This is the Safety Archive Page
 */
function safety_forms_archive_main() {
  return drupal_get_form('safety_forms_archive_form');
}

/**
 * Build our Safety Archive Form
 * Implements hook_menu()
 */

function safety_forms_archive_form($form, &$form_state) {

  // Get our db object
  $safety_obj = new Safety_Forms();

  $form['explain_text'] = array(
    '#type' => 'markup',
    '#markup' => "<details><summary>View Instructions</summary>
      <div class='user-message'>
      <ul>
          <li>Select a Form from the Filter Archive List dropdown.</li>
          <li>Click button to view the archived Form.</li>
          <li>Additionally filters for Month and Year.</li>
      </ul>
      </div></details>",
  );

  $form['filter_box'] = array(
    '#type' => 'container',
    '#attributes' => array('id' => 'filter-box'),
  );

  $form['filter_box']['unit_id_select'] = array(
    '#type' => 'select',
    '#title' => 'Filter Archive List',
    '#empty_option' => t('- Show All Repair Items -'),
    '#options' => array(
      'working_alone_checklist_form' => 'Working Alone Checklist Forms Archive',
      'near_miss_form' => 'Near Miss Forms Archive',
      'work_permits_form' => 'Work Permit Forms Archive',
      'monthly_meeting_form' => 'Monthly Meeting Forms Archive',
      'weekly_and_pre_job_meeting_form' => 'Weekly and Pre-Job Meeting Forms Archive',
      'jsa_form' => 'JSA Forms Archive',
      'hazard_id_form' => 'Hazard ID Forms Archive',
      'erp_drills_meeting_form' => 'ERP Drills Meeting Forms Archive',
    ),
    '#ajax' => array(
      'callback' => 'get_safety_forms_history_callback',
      'wrapper' => 'unit_select_wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['select_date'] = array(
    '#type' => 'select',
    '#title' => t('Filter Month'),
    '#empty_option' => t('- Filter Month -'),
    '#options' => array(
      'Jan' => 'Jan',
      'Feb' => 'Feb',
      'Mar' => 'Mar',
      'Apr' => 'Apr',
      'May' => 'May',
      'Jun' => 'Jun',
      'Jul' => 'Jul',
      'Aug' => 'Aug',
      'Sep' => 'Sep',
      'Oct' => 'Oct',
      'Nov' => 'Nov',
      'Dec' => 'Dec',
    ),
    '#prefix' => '<div class="select-date">',
    '#suffix' => '</div>',
    '#ajax' => array(
      'callback' => 'get_safety_forms_history_callback',
      'wrapper' => 'unit_select_wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['select_year'] = array(
    '#type' => 'select',
    '#title' => t('Filter Year'),
    '#empty_option' => t('- Filter Year -'),
    '#options' => drupal_map_assoc(array('2015','2016','2017','2018','2019','2020','2021','2022', '2023', '2024', '2025')),
    '#prefix' => '<div class="select-year">',
    '#suffix' => '</div>',
    '#ajax' => array(
      'callback' => 'get_safety_forms_history_callback',
      'wrapper' => 'unit_select_wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );


  // Show all repairs that are completed as a default
  $table = !empty($form_state['values']['unit_id_select']) ? $form_state['values']['unit_id_select'] : NULL;
  $month = !empty($form_state['values']['select_date']) ? $form_state['values']['select_date'] : NULL;
  $year = !empty($form_state['values']['select_year']) ? $form_state['values']['select_year'] : NULL;
//  $day = !empty($form_state['values']['select_day']) ? $form_state['values']['select_day'] : NULL;

  $output = ''; // To hold our list items
//  $safety_data = array(); // To hold our form data

  // Defaults query to the current month and year
  if(isset($table) && !isset($month)) {
    $safety_data = $safety_obj->get_safety_form_archive_data($table, $id = NULL, $month = NULL, $year = NULL, $permit_num = NULL, $jsa = NULL);
    $output .= safety_forms_build_archive_list($table, $safety_data);

  }
  // If filter by month was selected
  elseif(isset($table) && isset($month) && !isset($year)) {
    $safety_data = $safety_obj->get_safety_form_archive_data($table, $id = NULL, $month, $year = NULL,  $permit_num = NULL, $jsa = NULL);
    $output .= safety_forms_build_archive_list($table, $safety_data);
  }
  // If all 3 filters are being used
  elseif (isset($table) && isset($month) && isset($year)) {
    $safety_data = $safety_obj->get_safety_form_archive_data($table, $id = NULL, $month, $year, $permit_num = NULL, $jsa = NULL);
    $output .= safety_forms_build_archive_list($table, $safety_data);
  }

  // Build our pager
//  $build = '';
//  $per_page = 3;
//  // Initialize the pager
//  $current_page = pager_default_initialize(count($output['li']), $per_page);
//  // Split your list into page sized chunks
//  $chunks = array_chunk($output, $per_page, TRUE);
//
//  $build .= theme_table(
//      array(
//        "header" => array(),
//        "rows" => $chunks[$current_page],
//        "attributes" => array('class' => array('safety-forms-table')),
//        "sticky" => false, // Table header will be sticky
//        "caption" => "",
//        "colgroups" => array(),
//        "empty" => t('') // The message to be displayed if table is empty
//      )
//    ).theme("pager", array('quantity',count($output)));

//  $build = '';
//  $build .= theme_table(
//      array(
//        "header" => array('','',''),
//        "rows" => $output,
//        "attributes" => array('class' => array('safety-forms-table')),
//        "sticky" => false, // Table header will be sticky
//        "caption" => "",
//        "colgroups" => array(),
//        "empty" => t('') // The message to be displayed if table is empty
//      )
//    );


  $form['main_box'] = array(
    '#type' => 'container',
    '#id' => 'unit_select_wrapper',
  );

  $form['main_box']['links'] = array(
    '#markup' => '<div class="button-cont">' .  $output  . '</div>' . '<div id="content"></div>',
  );


  return $form;
}

/**
 * Ajax callback from select element
 */
function get_safety_forms_history_callback($form, &$form_state) {
  return $form['main_box'];
}

/**
 * @param $table
 * @param $safety_data
 * @return string
 * This custom function that returns our list off ajax buttons for the forms
 */
function safety_forms_build_archive_list($table, $safety_data) {

  $output = '';

  switch($table) {
    case 'working_alone_checklist_form':
      foreach ($safety_data as $key => $val) {
        // Format our list
        $output .= l(t('Working Alone Checklist Form ' . '#' . $val['id'] . ' ' . $val['date']),
            'safety_forms/working_alone_checklist_form_archive/' . $val['id'],
            array('attributes' => array('class' => array('btn btn-danger ajax-link'))));
      }
      break;

    case 'near_miss_form':
      foreach ($safety_data as $key => $val) {
        // Format our list
        $output .= l(t('Near Miss Form ' . '#' . $val['id'] . ' ' . $val['date']),
            'safety_forms/near_miss_form_archive/' . $val['id'],
            array('attributes' => array('class' => array('btn btn-danger ajax-link'))));
      }
      break;

    case 'weekly_and_pre_job_meeting_form':
      foreach ($safety_data as $key => $val) {
        // Format our list
        $output .= l(t('Weekly and Pre-Job Meeting Form ' . '#' . $val['id'] . ' ' . $val['date']),
            'safety_forms/weekly_and_pre_job_meeting_form_archive/' . $val['id'],
            array('attributes' => array('class' => array('btn btn-danger ajax-link'))));
      }
      break;

    case 'work_permits_form':
      foreach ($safety_data as $key => $val) {
        // Format our list
        $output .= l(t('Work Permit Form ' . '#' . $val['permit_num'] . ' ' . $val['date']),
            'safety_forms/work_permit_form_archive/' . $val['permit_num'],
            array('attributes' => array('class' => array('btn btn-danger ajax-link'))));
      }
      break;

    case 'monthly_meeting_form':
      foreach ($safety_data as $key => $val) {
        // Format our list
        $output .= l(t('Monthly Meeting Form ' . '#' . $val['id'] . ' ' . $val['date']),
            'safety_forms/monthly_meeting_form_archive/' . $val['id'],
            array('attributes' => array('class' => array('btn btn-danger ajax-link'))));
      }
      break;

    case 'jsa_form':
      foreach ($safety_data as $key => $val) {
        // Format our list
        $output .= l(t('JSA Form ' . '#' . $val['jsa_num'] . ' ' . $val['date']),
            'safety_forms/jsa_form_archive/' . $val['jsa_num'],
            array('attributes' => array('class' => array('btn btn-danger ajax-link'))));
      }
      break;

    case 'hazard_id_form':
      foreach ($safety_data as $key => $val) {
        // Format our list
        $output .= l(t('Hazard ID Form ' . '#' . $val['id'] . ' ' . $val['date']),
            'safety_forms/hazard_id_form_archive/' . $val['id'],
            array('attributes' => array('class' => array('btn btn-danger ajax-link'))));
      }
      break;

    case 'erp_drills_meeting_form':
      foreach ($safety_data as $key => $val) {
        // Format our list
        $output .= l(t('ERP Drills Meeting Form ' . '#' . $val['id'] . ' ' . $val['date']),
            'safety_forms/erp_drills_meeting_form_archive/' . $val['id'],
            array('attributes' => array('class' => array('btn btn-danger ajax-link'))));
      }
      break;
  }

  return $output;
}