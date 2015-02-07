<?php

drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/shop_and_yard_inspection_form.min.css');
drupal_add_js(drupal_get_path('module', 'safety_forms') . '/dist/js/shop_and_yard_inspection_form.min.js');

/**
 * Shop and Yard Inspection Form
 */
function shop_and_yard_inspection_form($form, &$form_state) {

  $data = array(
    'administrative' => array(
      'HS&E',
      'Employee Training',
      'ERP Plans & Contacts Posted',
      'ERP & Fire Drills Done',
      'MSDS Binder Current',
      'Emergency Exits Illuminated',
      'Safely Signs Posted',
      'JSAs Completed for Critical Tasks',
    ),
    'entrances to shop area' => array(
      'Requirements for PPE Posted',
      'Hazards, Warnings & Shop Rules'
    ),
    'general safety & housekeeping' => array(
      'Tools & Equipment Storage',
      'Floors Dry and Clean',
      'Work Areas Tidy & Free of Waste',
      'Trip Hazards Removed or Marked',
      'Exits Clear',
      'No Food or Drink in Work Area',
      'Proper Garbage & Waste Bins',
      'Workplace Hazard Signs',
      'Floor Drains Clear',
      'Washroom Facililies Clean',
      'Soap & Towels Available',
      'Lunch Room Clean',
    ),
    'personal protective equipment' => array(
      'Training, Care and Use of PPE including Gloves',
      'Respiratory Protection Available/Stored Properly',
    ),
    'eyewash' => array(
      'Eyewash Locations Properly Signed',
      'Access to Eyewash Station Clear',
      'Eyewash Stations Clean, Bottles Full',
      'Inspections & Fluid Changes Documented',
    ),
    'first aid' => array(
      'Location of First Aid Kits Identified & Accessible',
      'Box Clean, Stocked & Contents Not Expired',
    ),
    'noise control' => array(
      'Noise Hazard Areas Identified',
      'Hearing Protection Available',
      'Noise Levels Posted',
    ),
    'hand & power tools' => array(
      'Tools in Good Condition',
      'Guards in Place',
      'Grounded & Double Insulated',
      'Tool Storage Neat & Tidy',
    ),
    'ergonomics' => array(
      'Tables and Benches Height Suitable',
      'Machinery Easily Accessible',
      'Workers using Proper Grip & Lifting Techniques',
    ),
    'electrical safety' => array(
      'Electrical Panel Area Kept Clear',
      'Electrical Panels Closed',
      'Circuit Breakers Identified',
      'Condition of Extension Cords',
      'Lockout/Tagout Available',
    ),
    'fire safety equipment' => array(
      'Easy Access to Fire Extinguishers',
      'Monthly Inspections & Tags Marked',
      'Annual Maintenance Completed',
    ),
    'lighting' => array(
      'Protective Covers in Place',
      'Emergency Lighting Tested Monthly',
      'Burnt Bulbs Replaced',
    ),
    'material storage' => array(
      'Chemicals Properly Stored',
      'Slings & Rigging Inspected',
      'Materials Properly Stacked',
      'Flammable Liquids Stored Away from Exits',
      'Flammable Liquids more than 38 1itres/10 gals Stored in Approved Cabinets'
    ),
    'forklift and or loader' => array(
      'Operating Procedures/Manual',
      'Daily Inspection Checklist',
      'Operators Trained',
      'Seatbelts',
      'Back Up Warning',
      'Maintenance Documented',
      'Other',
    ),
    'waste & environmental management' => array(
      'Waste Separated for Recycling',
      'Waste Contained in Proper Bins',
      'Proper Oily Rag Containers',
      'Hazardous Material Properly Identified',
      'Hazardous Material Spill Plan',
    ),
    'lockout / tagout' => array(
      'Lockout Procedure Posted',
      'Lock/Tag/Try Process In Place',
      'Locks & Tags Available',
    ),
    'compressed gas cylinders' => array(
      'Cylinders Labeled and Secured',
      'Regulators, Hoses and Fittings Ok',
      'Empty & Full Cylinders Separated',
    ),
    'yard area' => array(
      'Gated & Fenced',
      'Exterior Lighting Working',
      'Designated Parking Area',
      'Pipe Racks Level',
      'Pipe Rack Stops Used',
      'Barrels & Tanks Properly Marked',
      'Fuel Tanks Properly Burmed',
      'Yard Housekeeping',
    ),
    'cranes & hoists' => array(
      'Daily Pre-Operational Checklist Completed',
      'Maintenance Recorded on Log Record',
      'Load Beam Rating Visible',
      'Lift Equipment Weight Limit Visible',
      'Annual Certification Completed',
      'Operating Manual Available',
      'Rope Inspection Completed',
      'Recommended Inspection Schedule and Maintenance as per Manual is Followed with Documentation Supporting',
    ),
  );

  // Start the form
  $form['main_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Shop and Yard Inspection Form'),
    '#id' => 'main-cont',
//    '#tree' => TRUE,
  );

  $form['main_container']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date'),
    '#default_value' => date('M d, Y'),
    '#disabled' => TRUE,
    '#prefix' => '<div class="date">',
    '#suffix' => '</div>',
  );

  $form['main_container']['submitted_by'] = array(
    '#type' => 'textfield',
    '#title' => t('Submitted By'),
    '#default_value' => '',
    '#required' => TRUE,
    '#prefix' => '<div class="submitted-by">',
    '#suffix' => '</div>',
  );


  $str = ''; // Declare var
  $new_key = '';
  $counter = 0;
  foreach ($data as $key => $val) {

    if(is_string($key)) {
      $new_key = prepare_string($key);
    }

    $form['main_container'][$new_key] = array(
      '#type' => 'fieldset',
      '#title' => ucwords($key),
      '#attributes' => array('class' => array('field-cont'), 'value' => $counter + 100),
      '#id' => $new_key,
      '#tree' => TRUE,
    );

    foreach ($val as $k => $v) {

      if(is_string($v)) {
        $str = prepare_string($v);
      }

      $form['main_container'][$new_key][$str] = array(
        '#type' => 'fieldset',
        '#id' => 'collapse_' . ($counter + 100),
//        '#tree' => TRUE,
        '#attributes' => array('class' => array('cont-box')),
      );

      // Add textfield instead of markup on the 'Other' val
      if ($v !== 'Other') {
        $form['main_container'][$new_key][$str]['title'] = array(
          '#markup' => $v,
          '#prefix' => '<div class="cont-title">',
          '#suffix' => '</div>',
        );
      }
      else {
        $form['main_container'][$new_key][$str]['title_text'] = array(
          '#type' => 'textfield',
          '#title' => $v,
          '#default_value' => '',
          '#prefix' => '<div class="cont-title">',
          '#suffix' => '</div>',
        );
      }

//      // If no other value than required is false
//      $other = isset($form_state['main_container'][$new_key][$str]['title_text']) ?
//        $form_state['main_container'][$new_key][$str]['title_text'] : NULL;

      $form['main_container'][$new_key][$str]['radios'] = array(
        '#type' => 'radios',
//        '#title' => t('Condition'),
        '#options' => array(
          'adequate' => 'Adequate',
          'inadequate' => 'Inadequate',
          'na' => 'Not Applicable',
        ),
//        '#required' => TRUE,
        '#prefix' => '<div class="cont-radios">',
        '#suffix' => '</div>',
      );

      $form['main_container'][$new_key][$str]['dropdown'] = array(
        '#type' => 'select',
//        '#title' => t('Hazard Class'),
        '#empty_option' => t('- Select Hazard Class -'),
        '#options' => array(
          'imminent_danger' => t('Imminent Danger'),
          'potential_injury' => t('Potential Injury'),
          'first_aid_minor_loss' => t('First Aid or Minor Loss'),
        ),
        '#prefix' => '<div class="cont-dropdown">',
        '#suffix' => '</div>',
//        '#required' => TRUE,
      );

      $counter = $counter + 1;
      $form['main_container'][$new_key][$str]['add_comments'] = array(
        '#type' => 'button',
        '#value' => t('Add Comments/Action Plans'),
        '#id' => 'button_' . $counter,
        '#attributes' => array('class' => array('add-comments'), 'value' => $counter),
        //        '#attributes' => array('class' => array('btn btn-danger'), 'data-toggle' => 'collapse', 'data-target' => '#collapse_' . $str,
//                               'aria-expanded' => FALSE, 'aria-controls' => 'collapse_' . $str),
        '#prefix' => '<div class="action-plan-button">',
        '#suffix' => '</div>',
      );

      $form['main_container'][$new_key][$str]['action_cont'] = array(
        '#type' => 'container',
        '#id' => 'collapse_' . $counter,
        '#attributes' => array('class' => array('action-cont')),
      );

      $form['main_container'][$new_key][$str]['action_cont']['comments'] = array(
        '#type' => 'textarea',
        '#title' => t('Comments'),
        '#attributes' => array('id' => 'comments_' . $str),
        '#rows' => 2,
        '#default_value' => '',
        '#prefix' => '<div class="comments">',
        '#suffix' => '</div>',
//        '#required' => TRUE,
      );

      $form['main_container'][$new_key][$str]['action_cont']['action_plan'] = array(
        '#type' => 'textarea',
        '#title' => t('Action Plan'),
        '#attributes' => array('id' => 'action_plan_' . $str),
        '#rows' => 2,
        '#default_value' => '',
        '#prefix' => '<div class="action-plan">',
        '#suffix' => '</div>',
        //        '#required' => TRUE,
      );

      /**-----------------------------Sub elements----------------------------------*/
      // Build our sub-elements when we hit the array value
      if($new_key === 'cranes__hoists' && $str === 'rope_inspection_completed') {

        $sub_data = array(
          'Check for Broken Wires',
          'No Swelling, Bruising, Permanent Bends, Kinks, Crushing, Bird Caging or Heavy Wear',
          'No Corrosion or Rust',
          'No Heat Damage from Any Source',
          'Is Properly Lubed',
        );
        $counter_2 = 1;
        foreach($sub_data as $h => $i) {

          $s_str = prepare_string($i); // Custom function

          $form['main_container'][$new_key][$str]['sub_ele_' . $h] = array(
            '#type' => 'fieldset',
            '#id' => $s_str,
            '#attributes' => array('class' => array('sub-cont-box')),
          );

          $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['title'] = array(
            '#markup' => $i,
            '#prefix' => '<div class="sub-cont-title">',
            '#suffix' => '</div>',
          );

          $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['radios'] = array(
            '#type' => 'radios',
            //        '#title' => t('Condition'),
            '#options' => array(
              'adequate' => 'Adequate',
              'inadequate' => 'Inadequate',
              'na' => 'Not Applicable',
            ),
            //    '#required' => TRUE,
            '#prefix' => '<div class="sub-cont-radios">',
            '#suffix' => '</div>',
          );

          $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['dropdown'] = array(
            '#type' => 'select',
            //        '#title' => t('Hazard Class'),
            '#empty_option' => t('- Select Hazard Class -'),
            '#options' => array(
              'imminent_danger' => t('Imminent Danger'),
              'potential_injury' => t('Potential Injury'),
              'first_aid_minor_loss' => t('First Aid or Minor Loss'),
            ),
            '#prefix' => '<div class="sub-cont-dropdown">',
            '#suffix' => '</div>',
            //    '#required' => TRUE,
          );

          $counter_2 = $counter_2 + 1;
          $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['add_comments'] = array(
            '#type' => 'button',
            '#id' => 'sub_btn_' . $counter_2,
            '#attributes' => array('class' => array('btn btn-danger add-comments'), 'value' => $counter_2 + 1000),
            '#value' => t('Add Comments/Action Plans'),
            '#prefix' => '<div class="action-plan-button">',
            '#suffix' => '</div>',
          );

          // Action plan
          $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['action_cont'] = array(
            '#type' => 'container',
            '#id' => 'collapse_' . ($counter_2 + 1000),
            '#attributes' => array('class' => array('action-cont')),
          );

          $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['action_cont']['comments'] = array(
            '#type' => 'textarea',
            '#title' => t('Comments'),
            '#attributes' => array('id' => 'comments_' . $s_str),
            '#rows' => 2,
            '#default_value' => '',
            '#prefix' => '<div class="comments">',
            '#suffix' => '</div>',
            //        '#required' => TRUE,
          );

          $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['action_cont']['action_plan'] = array(
            '#type' => 'textarea',
            '#title' => t('Action Plan'),
            '#attributes' => array('id' => 'action_plan_' . $s_str),
            '#rows' => 2,
            '#default_value' => '',
            '#prefix' => '<div class="action-plan">',
            '#suffix' => '</div>',
            //        '#required' => TRUE,
          );
        }
      } // End our sub-elements
    }
  }

  $form['main_container']['submit_button'] = array(
    '#type' => 'submit',
    '#value' => 'Submit Shop and Yard Inspection Form',
    '#id' => 'submit-btn'
    //    '#required' => TRUE,
  );


  return $form;
}

/**
 * Function for formatting our strings
 */
function prepare_string($str) {

  // Format the strings to what we need
  $string = str_replace('&', ' ', $str); // Get rid of & symbol
  $string = str_replace(' ', '_', $string); // Replace space with underscore
  $string = str_replace('(', ' ', $string); // Replace parentheses underscores
  $string = str_replace(')', ' ', $string); // Replace parentheses underscores

  $string = str_replace(',', '', $string); // Replace commas with underscores
  $string = str_replace('/', '_', $string); // Replace backslash underscores
  $string = str_replace('__', '_', $string); // Replace double underscores with single
  $string = str_replace('___', '_', $string); // Replace triplet underscores with single
  $string = strtolower($string);

  return $string;
}

/**+
 * Validate shop_and_yard_inspection_form
 */
function shop_and_yard_inspection_form_validate($form, &$form_state) {

  form_state_values_clean($form_state);

  $shop_data = array();

  foreach($form_state['values'] as $key => $val) {
    if(is_array($val)) {
      $shop_data[$key] = $val;
    }
  }

  $form_state['values']['shop_yard_data'] = serialize($shop_data);
}

/**
 * Submit shop_and_yard_inspection_form
 */
function shop_and_yard_inspection_form_submit($form, &$form_state) {

  $fields = array(
    'date' => $form_state['values']['date'],
    'submitted_by' => $form_state['values']['submitted_by'],
    'shop_yard_data' => $form_state['values']['shop_yard_data'],
    'timestamp' => time(),
  );

  $query = db_insert('shop_and_yard_inspection_form')
    ->fields($fields);

  $query->execute();

  if($query) {
    drupal_set_message('Your form has been submitted');
  }

  $form_state['redirect'] = 'safety_forms';


}