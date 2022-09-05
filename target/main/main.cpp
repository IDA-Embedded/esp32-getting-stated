/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <ExampleCode.hpp>

#ifdef __cplusplus
extern "C" {
#endif
void app_main(void);
// Your prototype or Definition
#ifdef __cplusplus
}
#endif

void app_main(void)
{
	 ExampleCode::startWifi();
	// ExampleCode::sendHttpText("Hello World!");
	// ExampleCode::captureImage();
	// ExampleCode::postImageToServer();
}
