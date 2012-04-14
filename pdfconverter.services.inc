<?php
/**
 * Implementation of hook_ctools_plugin_api().
 */
function pdfconverter_ctools_plugin_api($owner, $api) {
  if ($owner == 'services' && $api == 'services') {
    return array(
      'version' => 3,
      'file' => 'pdfconverter.services.inc', // Optional parameter to indicate the file name to load.
      'path' => drupal_get_path('module', 'pdfconverter'), // If specifying the file key, path is required.
    );
  }
}

/**
 * Implementation of hook_default_services_endpoint().
 */
function pdfconverter_default_services_endpoint() {
  $endpoints = array();

  $endpoint = new stdClass;
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'convert';
  $endpoint->title = 'Convert';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'convert';
  $endpoint->authentication = array();
  $endpoint->server_settings = array(
    'rest_server' => array(
      'formatters' => array(
        'json' => TRUE,
  			'bencode' => FALSE,
        'jsonp' => FALSE,
				'php' => FALSE,
  			'rss' => FALSE,
  			'xml' => FALSE,
  			'yaml' => FALSE,  
      )
    ),
    'parsers' => array(
      'application/json' => TRUE,
    	'application/vnd.php.serialized' => FALSE,
    	'application/x-www-form-urlencoded' => FALSE,
    	'application/x-yaml' => FALSE,
    	'multipart/form-data' => FALSE,
    )
  );
  $endpoint->resources = array(
	  'convert' => array(
	    'alias' => '',
	    'operations' => array(
	      'create' => array(
	        'enabled' => 1,
	      ),
	    ),
	  ),
  );
  $endpoint->debug = 1;
  $endpoint->status = 1;

  $endpoints[] = $endpoint;
  return $endpoints;
}

/**
 *
 * Implementation of hook_services_resources
 *
 * @return array
 * 	it returns an array with the url of main file and number of parts
 */
function pdfconverter_services_resources()
{
  return array(
  /**
   * Definition of convert service
   */
    'convert' => convert_service_definition(),
  );
}

/**
 * Function that returns the convert array
 * service definition
 */
function convert_service_definition() {
  return array(
    'create' => array(
      'help' => 'Retrieves the converted files data',
      'callback' => '_convert_retrieve',
      'access callback' => '_convert_access',
      'args' => array(
  			'args' => array(
          'name' => 'url',
          'type' => 'string',
  				'description' => 'The url of the file to be converted',
  				'source' => array('data'),
  				'optional' => 'false',
        ),
  		),
    ),
  );
}

function _convert_retrieve(){
	//system_retrieve_file($url, $destination = NULL, $managed = FALSE, $replace = FILE_EXISTS_RENAME)
	$result = new stdClass();
	$result->main_url = 'here';
	$result->parts = 5;
	return $result;
}


/**
 *
 * Access callback for convert service
 * @param $opt
 * 	the required access: view
 * @param $args
 * 	the arguments passed in the request, the first argument is the category id
 */
function _convert_access()
{
  $access = TRUE;

  return $access;
}