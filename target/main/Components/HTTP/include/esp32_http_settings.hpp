
#ifdef __ESP32__
#include <esp_http_client.h>

esp_err_t DEFAULT_http_event_handle(esp_http_client_event_t* evt)
{
	return ESP_OK;
}

esp_http_client_config_t DEFAULT_HTTP_CONFIG = {
	.url = "", /*!< HTTP URL, the information on the URL is most important, it overrides the other
			   fields below, if any */
	.host = "", /*!< Domain or IP as string */
	.port = 1880, /*!< Port to connect, default depend on esp_http_client_transport_t (80 or 443) */
	.username = nullptr, /*!< Using for Http authentication */
	.password = nullptr, /*!< Using for Http authentication */
	.auth_type =
		esp_http_client_auth_type_t::HTTP_AUTH_TYPE_NONE, /*!< Http authentication type, see
															 `esp_http_client_auth_type_t` */
	.path = "", /*!< HTTP Path, if not set, default is `/` */
	.query = "", /*!< HTTP query */
	.cert_pem = nullptr, /*!< SSL server certification, PEM format as string, if the client requires
					to verify server */
	.client_cert_pem = nullptr, /*!< SSL client certification, PEM format as string, if the server
						   requires to verify client */
	.client_key_pem = nullptr, /*!< SSL client key, PEM format as string, if the server requires to
						  verify client */
	.user_agent = "", /*!< The User Agent string to send with HTTP requests */
	.method = esp_http_client_method_t::HTTP_METHOD_GET, /*!< HTTP Method */
	.timeout_ms = 5000, /*!< Network timeout in milliseconds */
	.disable_auto_redirect = false, /*!< Disable HTTP automatic redirects */
	.max_redirection_count = 50, /*!< Max number of redirections on receiving HTTP redirect status
								 code, using default value if zero*/
	.max_authorization_retries = 5, /*!< Max connection retries on receiving HTTP unauthorized
									 status code, using default value if zero. Disables
									 authorization retry if -1*/
	.event_handler = DEFAULT_http_event_handle, /*!< HTTP Event Handle */
	.transport_type =
		esp_http_client_transport_t::HTTP_TRANSPORT_UNKNOWN, /*!< HTTP transport type, see
																 `esp_http_client_transport_t` */
	.buffer_size = 5120, /*!< HTTP receive buffer size */
	//.buffer_size_tx = 1024, /*!< HTTP transmit buffer size */
	.buffer_size_tx = 5120, /*!< HTTP transmit buffer size */
	.user_data = nullptr, /*!< HTTP user_data context */
	.is_async = false, /*!< Set asynchronous mode, only supported with HTTPS for now */
	.use_global_ca_store = true, /*!< Use a global ca_store for all the connections in which this
							   bool is set. */
	.skip_cert_common_name_check = true, /*!< Skip any validation of server certificate CN field */
	.keep_alive_enable = false, /*!< Enable keep-alive timeout */
	.keep_alive_idle = 5000, /*!< Keep-alive idle time. Default is 5 (second) */
	.keep_alive_interval = 50, /*!< Keep-alive interval time. Default is 5 (second) */
	.keep_alive_count = 50, /*!< Keep-alive packet retry send count. Default is 3 counts */
};
#endif