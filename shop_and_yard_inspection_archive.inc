<?php
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'safety_forms') . '/includes/class.safety_forms.inc.php');

drupal_add_css(drupal_get_path('module', 'safety_forms') . '/dist/css/min/shop_and_yard_inspection_form.min.css');
drupal_add_js(drupal_get_path('module', 'safety_forms') . '/dist/js/shop_and_yard_inspection_form.min.js');

/**
 * Shop and Yard Inspection Form
 */
function shop_and_yard_inspection_archive_form($form, &$form_state, $args) {

  $id = check_plain($args);

  $safety_obj = new Safety_Forms();
  $safety_data = $safety_obj->get_safety_form_archive_data('shop_and_yard_inspection_form', $id, $month = NULL, $year = NULL, $permit_num = NULL, $jsa = NULL);
  $shop_data = unserialize($safety_data[0]['shop_yard_data']);

  foreach ($safety_data as $main_val) {

    $data = array(
      'administrative' => array(
        'HS&E' => array(
          $shop_data['administrative']['hs_e']['radios'],
          $shop_data['administrative']['hs_e']['dropdown'],
          $shop_data['administrative']['hs_e']['action_cont']
        ),
        'Employee Training' => array(
          $shop_data['administrative']['employee_training']['radios'],
          $shop_data['administrative']['employee_training']['dropdown'],
          $shop_data['administrative']['employee_training']['action_cont']
        ),
        'ERP Plans & Contacts Posted' => array(
          $shop_data['administrative']['erp_plans__contacts_posted']['radios'],
          $shop_data['administrative']['erp_plans__contacts_posted']['dropdown'],
          $shop_data['administrative']['erp_plans__contacts_posted']['action_cont']
        ),
        'ERP & Fire Drills Done' => array(
          $shop_data['administrative']['erp__fire_drills_done']['radios'],
          $shop_data['administrative']['erp__fire_drills_done']['dropdown'],
          $shop_data['administrative']['erp__fire_drills_done']['action_cont']
        ),
        'MSDS Binder Current' => array(
          $shop_data['administrative']['msds_binder_current']['radios'],
          $shop_data['administrative']['msds_binder_current']['dropdown'],
          $shop_data['administrative']['msds_binder_current']['action_cont']
        ),
        'Emergency Exits Illuminated' => array(
          $shop_data['administrative']['emergency_exits_illuminated']['radios'],
          $shop_data['administrative']['emergency_exits_illuminated']['dropdown'],
          $shop_data['administrative']['emergency_exits_illuminated']['action_cont']
        ),
        'Safely Signs Posted' => array(
          $shop_data['administrative']['safely_signs_posted']['radios'],
          $shop_data['administrative']['safely_signs_posted']['dropdown'],
          $shop_data['administrative']['safely_signs_posted']['action_cont']
        ),
        'JSAs Completed for Critical Tasks' => array(
          $shop_data['administrative']['jsas_completed_for_critical_tasks']['radios'],
          $shop_data['administrative']['jsas_completed_for_critical_tasks']['dropdown'],
          $shop_data['administrative']['jsas_completed_for_critical_tasks']['action_cont']
        ),
      ),
      'entrances to shop area' => array(
        'Requirements for PPE Posted' => array(
          $shop_data['entrances_to_shop_area']['requirements_for_ppe_posted']['radios'],
          $shop_data['entrances_to_shop_area']['requirements_for_ppe_posted']['dropdown'],
          $shop_data['entrances_to_shop_area']['requirements_for_ppe_posted']['action_cont']
        ),
        'Hazards, Warnings & Shop Rules' => array(
          $shop_data['entrances_to_shop_area']['hazards_warnings__shop_rules']['radios'],
          $shop_data['entrances_to_shop_area']['hazards_warnings__shop_rules']['dropdown'],
          $shop_data['entrances_to_shop_area']['hazards_warnings__shop_rules']['action_cont']
        ),
      ),
      'general safety & housekeeping' => array(
        'Tools & Equipment Storage' => array(
          $shop_data['general_safety__housekeeping']['tools__equipment_storage']['radios'],
          $shop_data['general_safety__housekeeping']['tools__equipment_storage']['dropdown'],
          $shop_data['general_safety__housekeeping']['tools__equipment_storage']['action_cont']
        ),
        'Floors Dry and Clean' => array(
          $shop_data['general_safety__housekeeping']['floors_dry_and_clean']['radios'],
          $shop_data['general_safety__housekeeping']['floors_dry_and_clean']['dropdown'],
          $shop_data['general_safety__housekeeping']['floors_dry_and_clean']['action_cont']
        ),
        'Work Areas Tidy & Free of Waste' => array(
          $shop_data['general_safety__housekeeping']['work_areas_tidy__free_of_waste']['radios'],
          $shop_data['general_safety__housekeeping']['work_areas_tidy__free_of_waste']['dropdown'],
          $shop_data['general_safety__housekeeping']['work_areas_tidy__free_of_waste']['action_cont']
        ),
        'Trip Hazards Removed or Marked' => array(
          $shop_data['general_safety__housekeeping']['trip_hazards_removed_or_marked']['radios'],
          $shop_data['general_safety__housekeeping']['trip_hazards_removed_or_marked']['dropdown'],
          $shop_data['general_safety__housekeeping']['trip_hazards_removed_or_marked']['action_cont']
        ),
        'Exits Clear' => array(
          $shop_data['general_safety__housekeeping']['exits_clear']['radios'],
          $shop_data['general_safety__housekeeping']['exits_clear']['dropdown'],
          $shop_data['general_safety__housekeeping']['exits_clear']['action_cont']
        ),
        'No Food or Drink in Work Area' => array(
          $shop_data['general_safety__housekeeping']['no_food_or_drink_in_work_area']['radios'],
          $shop_data['general_safety__housekeeping']['no_food_or_drink_in_work_area']['dropdown'],
          $shop_data['general_safety__housekeeping']['no_food_or_drink_in_work_area']['action_cont']
        ),
        'Proper Garbage & Waste Bins' => array(
          $shop_data['general_safety__housekeeping']['proper_garbage__waste_bins']['radios'],
          $shop_data['general_safety__housekeeping']['proper_garbage__waste_bins']['dropdown'],
          $shop_data['general_safety__housekeeping']['proper_garbage__waste_bins']['action_cont']
        ),
        'Workplace Hazard Signs' => array(
          $shop_data['general_safety__housekeeping']['workplace_hazard_signs']['radios'],
          $shop_data['general_safety__housekeeping']['workplace_hazard_signs']['dropdown'],
          $shop_data['general_safety__housekeeping']['workplace_hazard_signs']['action_cont']
        ),
        'Floor Drains Clear' => array(
          $shop_data['general_safety__housekeeping']['floor_drains_clear']['radios'],
          $shop_data['general_safety__housekeeping']['floor_drains_clear']['dropdown'],
          $shop_data['general_safety__housekeeping']['floor_drains_clear']['action_cont']
        ),
        'Washroom Facililies Clean' => array(
          $shop_data['general_safety__housekeeping']['washroom_facililies_clean']['radios'],
          $shop_data['general_safety__housekeeping']['washroom_facililies_clean']['dropdown'],
          $shop_data['general_safety__housekeeping']['washroom_facililies_clean']['action_cont']
        ),
        'Soap & Towels Available' => array(
          $shop_data['general_safety__housekeeping']['soap__towels_available']['radios'],
          $shop_data['general_safety__housekeeping']['soap__towels_available']['dropdown'],
          $shop_data['general_safety__housekeeping']['soap__towels_available']['action_cont']
        ),
        'Lunch Room Clean' => array(
          $shop_data['general_safety__housekeeping']['lunch_room_clean']['radios'],
          $shop_data['general_safety__housekeeping']['lunch_room_clean']['dropdown'],
          $shop_data['general_safety__housekeeping']['lunch_room_clean']['action_cont']
        ),
      ),
      'personal protective equipment' => array(
        'Training, Care and Use of PPE including Gloves' => array(
          $shop_data['personal_protective_equipment']['training_care_and_use_of_ppe_including_gloves']['radios'],
          $shop_data['personal_protective_equipment']['training_care_and_use_of_ppe_including_gloves']['dropdown'],
          $shop_data['personal_protective_equipment']['training_care_and_use_of_ppe_including_gloves']['action_cont']
        ),
        'Respiratory Protection Available/Stored Properly' => array(
          $shop_data['personal_protective_equipment']['respiratory_protection_available_stored_properly']['radios'],
          $shop_data['personal_protective_equipment']['respiratory_protection_available_stored_properly']['dropdown'],
          $shop_data['personal_protective_equipment']['respiratory_protection_available_stored_properly']['action_cont']
        ),
      ),
      'eyewash' => array(
        'Eyewash Locations Properly Signed' => array(
          $shop_data['eyewash']['eyewash_locations_properly_signed']['radios'],
          $shop_data['eyewash']['eyewash_locations_properly_signed']['dropdown'],
          $shop_data['eyewash']['eyewash_locations_properly_signed']['action_cont']
        ),
        'Access to Eyewash Station Clear' => array(
          $shop_data['eyewash']['access_to_eyewash_station_clear']['radios'],
          $shop_data['eyewash']['access_to_eyewash_station_clear']['dropdown'],
          $shop_data['eyewash']['access_to_eyewash_station_clear']['action_cont']
        ),
        'Eyewash Stations Clean, Bottles Full' => array(
          $shop_data['eyewash']['eyewash_stations_clean_bottles_full']['radios'],
          $shop_data['eyewash']['eyewash_stations_clean_bottles_full']['dropdown'],
          $shop_data['eyewash']['eyewash_stations_clean_bottles_full']['action_cont']
        ),
        'Inspections & Fluid Changes Documented' => array(
          $shop_data['eyewash']['inspections__fluid_changes_documented']['radios'],
          $shop_data['eyewash']['inspections__fluid_changes_documented']['dropdown'],
          $shop_data['eyewash']['inspections__fluid_changes_documented']['action_cont']
        ),
      ),
      'first aid' => array(
        'Location of First Aid Kits Identified & Accessible' => array(
          $shop_data['first_aid']['location_of_first_aid_kits_identified__accessible']['radios'],
          $shop_data['first_aid']['location_of_first_aid_kits_identified__accessible']['dropdown'],
          $shop_data['first_aid']['location_of_first_aid_kits_identified__accessible']['action_cont']
        ),
        'Box Clean, Stocked & Contents Not Expired' => array(
          $shop_data['first_aid']['box_clean_stocked__contents_not_expired']['radios'],
          $shop_data['first_aid']['box_clean_stocked__contents_not_expired']['dropdown'],
          $shop_data['first_aid']['box_clean_stocked__contents_not_expired']['action_cont']
        ),
      ),
      'noise control' => array(
        'Noise Hazard Areas Identified' => array(
          $shop_data['noise_control']['noise_hazard_areas_identified']['radios'],
          $shop_data['noise_control']['noise_hazard_areas_identified']['dropdown'],
          $shop_data['noise_control']['noise_hazard_areas_identified']['action_cont']
        ),
        'Hearing Protection Available' => array(
          $shop_data['noise_control']['hearing_protection_available']['radios'],
          $shop_data['noise_control']['hearing_protection_available']['dropdown'],
          $shop_data['noise_control']['hearing_protection_available']['action_cont']
        ),
        'Noise Levels Posted' => array(
          $shop_data['noise_control']['noise_levels_posted']['radios'],
          $shop_data['noise_control']['noise_levels_posted']['dropdown'],
          $shop_data['noise_control']['noise_levels_posted']['action_cont']
        ),
      ),
      'hand & power tools' => array(
        'Tools in Good Condition' => array(
          $shop_data['hand__power_tools']['tools_in_good_condition']['radios'],
          $shop_data['hand__power_tools']['tools_in_good_condition']['dropdown'],
          $shop_data['hand__power_tools']['tools_in_good_condition']['action_cont']
        ),
        'Guards in Place' => array(
          $shop_data['hand__power_tools']['guards_in_place']['radios'],
          $shop_data['hand__power_tools']['guards_in_place']['dropdown'],
          $shop_data['hand__power_tools']['guards_in_place']['action_cont']
        ),
        'Grounded & Double Insulated' => array(
          $shop_data['hand__power_tools']['grounded__double_insulated']['radios'],
          $shop_data['hand__power_tools']['grounded__double_insulated']['dropdown'],
          $shop_data['hand__power_tools']['grounded__double_insulated']['action_cont']
        ),
        'Tool Storage Neat & Tidy' => array(
          $shop_data['hand__power_tools']['tool_storage_neat__tidy']['radios'],
          $shop_data['hand__power_tools']['tool_storage_neat__tidy']['dropdown'],
          $shop_data['hand__power_tools']['tool_storage_neat__tidy']['action_cont']
        ),
      ),
      'ergonomics' => array(
        'Tables and Benches Height Suitable' => array(
          $shop_data['ergonomics']['tables_and_benches_height_suitable']['radios'],
          $shop_data['ergonomics']['tables_and_benches_height_suitable']['dropdown'],
          $shop_data['ergonomics']['tables_and_benches_height_suitable']['action_cont']
        ),
        'Machinery Easily Accessible' => array(
          $shop_data['ergonomics']['machinery_easily_accessible']['radios'],
          $shop_data['ergonomics']['machinery_easily_accessible']['dropdown'],
          $shop_data['ergonomics']['machinery_easily_accessible']['action_cont']
        ),
        'Workers using Proper Grip & Lifting Techniques' => array(
          $shop_data['ergonomics']['workers_using_proper_grip__lifting_techniques']['radios'],
          $shop_data['ergonomics']['workers_using_proper_grip__lifting_techniques']['dropdown'],
          $shop_data['ergonomics']['workers_using_proper_grip__lifting_techniques']['action_cont']
        ),
      ),
      'electrical safety' => array(
        'Electrical Panel Area Kept Clear' => array(
          $shop_data['electrical_safety']['electrical_panel_area_kept_clear']['radios'],
          $shop_data['electrical_safety']['electrical_panel_area_kept_clear']['dropdown'],
          $shop_data['electrical_safety']['electrical_panel_area_kept_clear']['action_cont']
        ),
        'Electrical Panels Closed' => array(
          $shop_data['electrical_safety']['electrical_panels_closed']['radios'],
          $shop_data['electrical_safety']['electrical_panels_closed']['dropdown'],
          $shop_data['electrical_safety']['electrical_panels_closed']['action_cont']
        ),
        'Circuit Breakers Identified' => array(
          $shop_data['electrical_safety']['circuit_breakers_identified']['radios'],
          $shop_data['electrical_safety']['circuit_breakers_identified']['dropdown'],
          $shop_data['electrical_safety']['circuit_breakers_identified']['action_cont']
        ),
        'Condition of Extension Cords' => array(
          $shop_data['electrical_safety']['condition_of_extension_cords']['radios'],
          $shop_data['electrical_safety']['condition_of_extension_cords']['dropdown'],
          $shop_data['electrical_safety']['condition_of_extension_cords']['action_cont']
        ),
        'Lockout/Tagout Available' => array(
          $shop_data['electrical_safety']['lockout_tagout_available']['radios'],
          $shop_data['electrical_safety']['lockout_tagout_available']['dropdown'],
          $shop_data['electrical_safety']['lockout_tagout_available']['action_cont']
        ),
      ),
      'fire safety equipment' => array(
        'Easy Access to Fire Extinguishers' => array(
          $shop_data['fire_safety_equipment']['easy_access_to_fire_extinguishers']['radios'],
          $shop_data['fire_safety_equipment']['easy_access_to_fire_extinguishers']['dropdown'],
          $shop_data['fire_safety_equipment']['easy_access_to_fire_extinguishers']['action_cont']
        ),
        'Monthly Inspections & Tags Marked' => array(
          $shop_data['fire_safety_equipment']['monthly_inspections__tags_marked']['radios'],
          $shop_data['fire_safety_equipment']['monthly_inspections__tags_marked']['dropdown'],
          $shop_data['fire_safety_equipment']['monthly_inspections__tags_marked']['action_cont']
        ),
        'Annual Maintenance Completed' => array(
          $shop_data['fire_safety_equipment']['annual_maintenance_completed']['radios'],
          $shop_data['fire_safety_equipment']['annual_maintenance_completed']['dropdown'],
          $shop_data['fire_safety_equipment']['annual_maintenance_completed']['action_cont']
        ),
      ),
      'lighting' => array(
        'Protective Covers in Place' => array(
          $shop_data['lighting']['protective_covers_in_place']['radios'],
          $shop_data['lighting']['protective_covers_in_place']['dropdown'],
          $shop_data['lighting']['protective_covers_in_place']['action_cont']
        ),
        'Emergency Lighting Tested Monthly' => array(
          $shop_data['lighting']['emergency_lighting_tested_monthly']['radios'],
          $shop_data['lighting']['emergency_lighting_tested_monthly']['dropdown'],
          $shop_data['lighting']['emergency_lighting_tested_monthly']['action_cont']
        ),
        'Burnt Bulbs Replaced' => array(
          $shop_data['lighting']['burnt_bulbs_replaced']['radios'],
          $shop_data['lighting']['burnt_bulbs_replaced']['dropdown'],
          $shop_data['lighting']['burnt_bulbs_replaced']['action_cont']
        ),
      ),
      'material storage' => array(
        'Chemicals Properly Stored' => array(
          $shop_data['material_storage']['chemicals_properly_stored']['radios'],
          $shop_data['material_storage']['chemicals_properly_stored']['dropdown'],
          $shop_data['material_storage']['chemicals_properly_stored']['action_cont']
        ),
        'Slings & Rigging Inspected' => array(
          $shop_data['material_storage']['slings__rigging_inspected']['radios'],
          $shop_data['material_storage']['slings__rigging_inspected']['dropdown'],
          $shop_data['material_storage']['slings__rigging_inspected']['action_cont']
        ),
        'Materials Properly Stacked' => array(
          $shop_data['material_storage']['materials_properly_stacked']['radios'],
          $shop_data['material_storage']['materials_properly_stacked']['dropdown'],
          $shop_data['material_storage']['materials_properly_stacked']['action_cont']
        ),
        'Flammable Liquids Stored Away from Exits' => array(
          $shop_data['material_storage']['flammable_liquids_stored_away_from_exits']['radios'],
          $shop_data['material_storage']['flammable_liquids_stored_away_from_exits']['dropdown'],
          $shop_data['material_storage']['flammable_liquids_stored_away_from_exits']['action_cont']
        ),
        'Flammable Liquids more than 38 1itres (10 gals) Stored in Approved Cabinets' => array(
          $shop_data['material_storage']['flammable_liquids_more_than_38_1itres_ 10_gals _stored_in_approved_cabinets']['radios'],
          $shop_data['material_storage']['flammable_liquids_more_than_38_1itres_ 10_gals _stored_in_approved_cabinets']['dropdown'],
          $shop_data['material_storage']['flammable_liquids_more_than_38_1itres_ 10_gals _stored_in_approved_cabinets']['action_cont']
        ),
      ),
      'forklift and or loader' => array(
        'Operating Procedures/Manual' => array(
          $shop_data['forklift_and_or_loader']['operating_procedures_manual']['radios'],
          $shop_data['forklift_and_or_loader']['operating_procedures_manual']['dropdown'],
          $shop_data['forklift_and_or_loader']['operating_procedures_manual']['action_cont']
        ),
        'Daily Inspection Checklist' => array(
          $shop_data['forklift_and_or_loader']['daily_inspection_checklist']['radios'],
          $shop_data['forklift_and_or_loader']['daily_inspection_checklist']['dropdown'],
          $shop_data['forklift_and_or_loader']['daily_inspection_checklist']['action_cont']
        ),
        'Operators Trained' => array(
          $shop_data['forklift_and_or_loader']['operators_trained']['radios'],
          $shop_data['forklift_and_or_loader']['operators_trained']['dropdown'],
          $shop_data['forklift_and_or_loader']['operators_trained']['action_cont']
        ),
        'Seatbelts' => array(
          $shop_data['forklift_and_or_loader']['seatbelts']['radios'],
          $shop_data['forklift_and_or_loader']['seatbelts']['dropdown'],
          $shop_data['forklift_and_or_loader']['seatbelts']['action_cont']
        ),
        'Back Up Warning' => array(
          $shop_data['forklift_and_or_loader']['back_up_warning']['radios'],
          $shop_data['forklift_and_or_loader']['back_up_warning']['dropdown'],
          $shop_data['forklift_and_or_loader']['back_up_warning']['action_cont']
        ),
        'Maintenance Documented' => array(
          $shop_data['forklift_and_or_loader']['maintenance_documented']['radios'],
          $shop_data['forklift_and_or_loader']['maintenance_documented']['dropdown'],
          $shop_data['forklift_and_or_loader']['maintenance_documented']['action_cont']
        ),
        'Other' => array(
          $shop_data['forklift_and_or_loader']['other']['title_text'],
          $shop_data['forklift_and_or_loader']['other']['radios'],
          $shop_data['forklift_and_or_loader']['other']['dropdown'],
          $shop_data['forklift_and_or_loader']['other']['action_cont']
        ),
      ),
      'waste & environmental management' => array(
        'Waste Separated for Recycling' => array(
          $shop_data['waste__environmental_management']['waste_separated_for_recycling']['radios'],
          $shop_data['waste__environmental_management']['waste_separated_for_recycling']['dropdown'],
          $shop_data['waste__environmental_management']['waste_separated_for_recycling']['action_cont']
        ),
        'Waste Contained in Proper Bins' => array(
          $shop_data['waste__environmental_management']['waste_contained_in_proper_bins']['radios'],
          $shop_data['waste__environmental_management']['waste_contained_in_proper_bins']['dropdown'],
          $shop_data['waste__environmental_management']['waste_contained_in_proper_bins']['action_cont']
        ),
        'Proper Oily Rag Containers' => array(
          $shop_data['waste__environmental_management']['proper_oily_rag_containers']['radios'],
          $shop_data['waste__environmental_management']['proper_oily_rag_containers']['dropdown'],
          $shop_data['waste__environmental_management']['proper_oily_rag_containers']['action_cont']
        ),
        'Hazardous Material Properly Identified' => array(
          $shop_data['waste__environmental_management']['hazardous_material_properly_identified']['radios'],
          $shop_data['waste__environmental_management']['hazardous_material_properly_identified']['dropdown'],
          $shop_data['waste__environmental_management']['hazardous_material_properly_identified']['action_cont']
        ),
        'Hazardous Material Spill Plan' => array(
          $shop_data['waste__environmental_management']['hazardous_material_spill_plan']['radios'],
          $shop_data['waste__environmental_management']['hazardous_material_spill_plan']['dropdown'],
          $shop_data['waste__environmental_management']['hazardous_material_spill_plan']['action_cont']
        ),
      ),
      'lockout / tagout' => array(
        'Lockout Procedure Posted' => array(
          $shop_data['lockout__tagout']['lockout_procedure_posted']['radios'],
          $shop_data['lockout__tagout']['lockout_procedure_posted']['dropdown'],
          $shop_data['lockout__tagout']['lockout_procedure_posted']['action_cont']
        ),
        'Lock/Tag/Try Process In Place' => array(
          $shop_data['lockout__tagout']['lock_tag_try_process_in_place']['radios'],
          $shop_data['lockout__tagout']['lock_tag_try_process_in_place']['dropdown'],
          $shop_data['lockout__tagout']['lock_tag_try_process_in_place']['action_cont']
        ),
        'Locks & Tags Available' => array(
          $shop_data['lockout__tagout']['locks__tags_available']['radios'],
          $shop_data['lockout__tagout']['locks__tags_available']['dropdown'],
          $shop_data['lockout__tagout']['locks__tags_available']['action_cont']
        ),
      ),
      'compressed gas cylinders' => array(
        'Cylinders Labeled and Secured' => array(
          $shop_data['compressed_gas_cylinders']['cylinders_labeled_and_secured']['radios'],
          $shop_data['compressed_gas_cylinders']['cylinders_labeled_and_secured']['dropdown'],
          $shop_data['compressed_gas_cylinders']['cylinders_labeled_and_secured']['action_cont']
        ),
        'Regulators, Hoses and Fittings Ok' => array(
          $shop_data['compressed_gas_cylinders']['regulators_hoses_and_fittings_ok']['radios'],
          $shop_data['compressed_gas_cylinders']['regulators_hoses_and_fittings_ok']['dropdown'],
          $shop_data['compressed_gas_cylinders']['regulators_hoses_and_fittings_ok']['action_cont']
        ),
        'Empty & Full Cylinders Separated' => array(
          $shop_data['compressed_gas_cylinders']['empty__full_cylinders_separated']['radios'],
          $shop_data['compressed_gas_cylinders']['empty__full_cylinders_separated']['dropdown'],
          $shop_data['compressed_gas_cylinders']['empty__full_cylinders_separated']['action_cont']
        ),
      ),
      'yard area' => array(
        'Gated & Fenced' => array(
          $shop_data['yard_area']['gated__fenced']['radios'],
          $shop_data['yard_area']['gated__fenced']['dropdown'],
          $shop_data['yard_area']['gated__fenced']['action_cont']
        ),
        'Exterior Lighting Working' => array(
          $shop_data['yard_area']['exterior_lighting_working']['radios'],
          $shop_data['yard_area']['exterior_lighting_working']['dropdown'],
          $shop_data['yard_area']['exterior_lighting_working']['action_cont']
        ),
        'Designated Parking Area' => array(
          $shop_data['yard_area']['designated_parking_area']['radios'],
          $shop_data['yard_area']['designated_parking_area']['dropdown'],
          $shop_data['yard_area']['designated_parking_area']['action_cont']
        ),
        'Pipe Racks Level' => array(
          $shop_data['yard_area']['pipe_racks_level']['radios'],
          $shop_data['yard_area']['pipe_racks_level']['dropdown'],
          $shop_data['yard_area']['pipe_racks_level']['action_cont']
        ),
        'Pipe Rack Stops Used' => array(
          $shop_data['yard_area']['pipe_rack_stops_used']['radios'],
          $shop_data['yard_area']['pipe_rack_stops_used']['dropdown'],
          $shop_data['yard_area']['pipe_rack_stops_used']['action_cont']
        ),
        'Barrels & Tanks Properly Marked' => array(
          $shop_data['yard_area']['barrels__tanks_properly_marked']['radios'],
          $shop_data['yard_area']['barrels__tanks_properly_marked']['dropdown'],
          $shop_data['yard_area']['barrels__tanks_properly_marked']['action_cont']
        ),
        'Fuel Tanks Properly Burmed' => array(
          $shop_data['yard_area']['fuel_tanks_properly_burmed']['radios'],
          $shop_data['yard_area']['fuel_tanks_properly_burmed']['dropdown'],
          $shop_data['yard_area']['fuel_tanks_properly_burmed']['action_cont']
        ),
        'Yard Housekeeping' => array(
          $shop_data['yard_area']['yard_housekeeping']['radios'],
          $shop_data['yard_area']['yard_housekeeping']['dropdown'],
          $shop_data['yard_area']['yard_housekeeping']['action_cont']
        ),
      ),
      'cranes & hoists' => array(
        'Daily Pre-Operational Checklist Completed' => array(
          $shop_data['cranes__hoists']['daily_pre-operational_checklist_completed']['radios'],
          $shop_data['cranes__hoists']['daily_pre-operational_checklist_completed']['dropdown'],
          $shop_data['cranes__hoists']['daily_pre-operational_checklist_completed']['action_cont']
        ),
        'Maintenance Recorded on Log Record' => array(
          $shop_data['cranes__hoists']['maintenance_recorded_on_log_record']['radios'],
          $shop_data['cranes__hoists']['maintenance_recorded_on_log_record']['dropdown'],
          $shop_data['cranes__hoists']['maintenance_recorded_on_log_record']['action_cont']
        ),
        'Load Beam Rating Visible' => array(
          $shop_data['cranes__hoists']['load_beam_rating_visible']['radios'],
          $shop_data['cranes__hoists']['load_beam_rating_visible']['dropdown'],
          $shop_data['cranes__hoists']['load_beam_rating_visible']['action_cont']
        ),
        'Lift Equipment Weight Limit Visible' => array(
          $shop_data['cranes__hoists']['lift_equipment_weight_limit_visible']['radios'],
          $shop_data['cranes__hoists']['lift_equipment_weight_limit_visible']['dropdown'],
          $shop_data['cranes__hoists']['lift_equipment_weight_limit_visible']['action_cont']
        ),
        'Annual Certification Completed' => array(
          $shop_data['cranes__hoists']['annual_certification_completed']['radios'],
          $shop_data['cranes__hoists']['annual_certification_completed']['dropdown'],
          $shop_data['cranes__hoists']['annual_certification_completed']['action_cont']
        ),
        'Operating Manual Available' => array(
          $shop_data['cranes__hoists']['operating_manual_available']['radios'],
          $shop_data['cranes__hoists']['operating_manual_available']['dropdown'],
          $shop_data['cranes__hoists']['operating_manual_available']['action_cont']
        ),
        'Rope Inspection Completed' => array(
          $shop_data['cranes__hoists']['rope_inspection_completed']['radios'],
          $shop_data['cranes__hoists']['rope_inspection_completed']['dropdown'],
          $shop_data['cranes__hoists']['rope_inspection_completed']['action_cont']
        ),
        'Recommended Inspection Schedule and Maintenance as per Manual is Followed with Documentation Supporting' => array(
          $shop_data['cranes__hoists']['recommended_inspection_schedule_and_maintenance_as_per_manual_is_followed_with_documentation_supporting']['radios'],
          $shop_data['cranes__hoists']['recommended_inspection_schedule_and_maintenance_as_per_manual_is_followed_with_documentation_supporting']['dropdown'],
          $shop_data['cranes__hoists']['recommended_inspection_schedule_and_maintenance_as_per_manual_is_followed_with_documentation_supporting']['action_cont']
        ),
      ),
    );

    // Start the form
    $form['main_container'] = array(
      '#type' => 'fieldset',
      '#title' => t('Shop and Yard Inspection Form # ' .$id ),
      '#id' => 'main-cont',
      //    '#tree' => TRUE,
    );

    $form['main_container']['date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date'),
      '#default_value' => $main_val['date'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="date">',
      '#suffix' => '</div>',
    );

    $form['main_container']['submitted_by'] = array(
      '#type' => 'textfield',
      '#title' => t('Submitted By'),
      '#default_value' => $main_val['submitted_by'],
      '#disabled' => TRUE,
      '#prefix' => '<div class="submitted-by">',
      '#suffix' => '</div>',
    );

    $str = ''; // Declare var
    $new_key = '';
    $counter = 0;
    foreach ($data as $key => $val) {

      if (is_string($key)) {
        $new_key = prepare_string($key);
      }

      $form['main_container'][$new_key] = array(
        '#type' => 'fieldset',
        '#title' => ucwords($key),
        '#attributes' => array(
          'class' => array('field-cont'),
          'value' => $counter + 100
        ),
        '#id' => $new_key,
        '#tree' => TRUE,
      );

      foreach ($val as $k => $v) {

        if (is_string($k)) {
          $str = prepare_string($k);
        }

        $form['main_container'][$new_key][$str] = array(
          '#type' => 'fieldset',
          '#id' => 'collapse_' . ($counter + 100),
          //        '#tree' => TRUE,
          '#attributes' => array('class' => array('cont-box')),
        );
//        dsm($v);
        // Structure row for Other element which has textfield instead of markup
        if ($k !== 'Other') {
          $form['main_container'][$new_key][$str]['title'] = array(
            '#markup' => $k,
            '#prefix' => '<div class="cont-title">',
            '#suffix' => '</div>',
          );
        }
        else {
          $form['main_container'][$new_key][$str]['title_text'] = array(
            '#type' => 'textfield',
            '#title' => $k,
            '#default_value' => $v[0],
            '#disabled' => TRUE,
            '#prefix' => '<div class="cont-title">',
            '#suffix' => '</div>',
          );
        }

        $form['main_container'][$new_key][$str]['radios'] = array(
          '#type' => 'radios',
          '#default_value' => $k === 'Other' ? $v[1] : $v[0],
          '#options' => array(
            'adequate' => 'Adequate',
            'inadequate' => 'Inadequate',
            'na' => 'Not Applicable',
          ),
          '#disabled' => TRUE,
          '#prefix' => '<div class="cont-radios">',
          '#suffix' => '</div>',
        );

        $form['main_container'][$new_key][$str]['dropdown'] = array(
          '#type' => 'select',
          '#default_value' => $k === 'Other' ? $v[2] : $v[1],
          '#empty_option' => t('- Select Hazard Class -'),
          '#options' => array(
            'imminent_danger' => t('Imminent Danger'),
            'potential_injury' => t('Potential Injury'),
            'first_aid_minor_loss' => t('First Aid or Minor Loss'),
          ),
          '#disabled' => TRUE,
          '#prefix' => '<div class="cont-dropdown">',
          '#suffix' => '</div>',
          //    '#required' => TRUE,
        );

        $counter = $counter + 1;
//        $form['main_container'][$new_key][$str]['add_comments'] = array(
//          '#type' => 'button',
//          '#value' => t('Add Comments/Action Plans'),
//          '#id' => 'button_' . $counter,
//          '#attributes' => array(
//            'class' => array('add-comments'),
//            'value' => $counter
//          ),
//          '#disabled' => TRUE,
//          '#prefix' => '<div class="action-plan-button">',
//          '#suffix' => '</div>',
//        );


        $form['main_container'][$new_key][$str]['action_cont'] = array(
          '#type' => 'container',
          '#id' => 'collapse_' . $counter,
          '#attributes' => array('class' => array('action-cont')),
        );

        foreach (($k === 'Other' ? $v[3] : $v[2]) as $t) {

          $form['main_container'][$new_key][$str]['action_cont']['comments'] = array(
            '#type' => 'textarea',
            '#title' => t('Comments'),
            '#attributes' => array('id' => 'comments_' . $str),
            '#rows' => 2,
            '#default_value' => $t,
            '#disabled' => TRUE,
            '#prefix' => '<div class="comments">',
            '#suffix' => '</div>',
            //        '#required' => TRUE,
          );

          $form['main_container'][$new_key][$str]['action_cont']['action_plan'] = array(
            '#type' => 'textarea',
            '#title' => t('Action Plan'),
            '#attributes' => array('id' => 'action_plan_' . $str),
            '#rows' => 2,
            '#disabled' => TRUE,
            '#default_value' => $t,
            '#prefix' => '<div class="action-plan">',
            '#suffix' => '</div>',
            //        '#required' => TRUE,
          );
        }

        /**-----------------------------Sub elements----------------------------------*/
        // Build our sub-elements when we hit the array value
        if ($new_key === 'cranes__hoists' && $str === 'rope_inspection_completed') {

          $sub_data = array(
            array('Check for Broken Wires', $shop_data['cranes__hoists']['rope_inspection_completed']['sub_ele_0']),
            array('No Swelling, Bruising, Permanent Bends, Kinks, Crushing, Bird Caging or Heavy Wear', $shop_data['cranes__hoists']['rope_inspection_completed']['sub_ele_1']),
            array('No Corrosion or Rust', $shop_data['cranes__hoists']['rope_inspection_completed']['sub_ele_2']),
            array('No Heat Damage from Any Source', $shop_data['cranes__hoists']['rope_inspection_completed']['sub_ele_3']),
            array('Is Properly Lubed',$shop_data['cranes__hoists']['rope_inspection_completed']['sub_ele_4']),
          );

          $counter_2 = 0;
          foreach ($sub_data as $h => $i) {

            $s_str = prepare_string($i[0]); // Custom function

            foreach ($i[1] as $n => $p) {

              $form['main_container'][$new_key][$str]['sub_ele_' . $h] = array(
                '#type' => 'fieldset',
                '#id' => $str . '_' . $h,
                '#attributes' => array('class' => array('sub-cont-box')),
              );

              $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['title'] = array(
                '#markup' => $i[0],
                '#prefix' => '<div class="sub-cont-title">',
                '#suffix' => '</div>',
              );

              $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['radios'] = array(
                '#type' => 'radios',
                '#default_value' => $p['radios'],
                '#options' => array(
                  'adequate' => 'Adequate',
                  'inadequate' => 'Inadequate',
                  'na' => 'Not Applicable',
                ),
                '#disabled' => TRUE,
                '#prefix' => '<div class="sub-cont-radios">',
                '#suffix' => '</div>',
              );

              $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['dropdown'] = array(
                '#type' => 'select',
                '#default_value' => $p['dropdown'],
                '#empty_option' => t('- Select Hazard Class -'),
                '#options' => array(
                  'imminent_danger' => t('Imminent Danger'),
                  'potential_injury' => t('Potential Injury'),
                  'first_aid_minor_loss' => t('First Aid or Minor Loss'),
                ),
                '#prefix' => '<div class="sub-cont-dropdown">',
                '#suffix' => '</div>',
                '#disabled' => TRUE,
              );

              $counter_2 = $counter_2 + 1;
//              $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['add_comments'] = array(
//                '#type' => 'button',
//                '#id' => 'sub_btn_' . $counter_2,
//                '#attributes' => array(
//                  'class' => array('btn btn-danger add-comments'),
//                  'value' => $counter_2 + 1000
//                ),
//                '#value' => t('Add Comments/Action Plans'),
//                '#prefix' => '<div class="action-plan-button">',
//                '#suffix' => '</div>',
//              );

              // Action plan
              $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['action_cont'] = array(
                '#type' => 'container',
                '#id' => 'collapse_' . ($counter_2 + 1000),
                '#attributes' => array('class' => array('action-cont')),
              );

              // Spit out the radio fields
              foreach ($p['action_cont'] as $a) {

                $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['action_cont']['comments'] = array(
                  '#type' => 'textarea',
                  '#title' => t('Comments'),
                  '#attributes' => array('id' => 'comments_' . $s_str),
                  '#rows' => 2,
                  '#default_value' => $a,
                  '#prefix' => '<div class="comments">',
                  '#suffix' => '</div>',
                  '#disabled' => TRUE,
                );

                $form['main_container'][$new_key][$str]['sub_ele_' . $h][$s_str]['action_cont']['action_plan'] = array(
                  '#type' => 'textarea',
                  '#title' => t('Action Plan'),
                  '#attributes' => array('id' => 'action_plan_' . $s_str),
                  '#rows' => 2,
                  '#default_value' => $a,
                  '#prefix' => '<div class="action-plan">',
                  '#suffix' => '</div>',
                  '#disabled' => TRUE,
                );
              }
            }
          }
        } // End our sub-elements
      }
    }
  }
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
