/*
#
# Copyright (C) 2022 ArrowOS
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"


#include "init_msm8226.h"

using android::base::GetProperty;

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("G7105") == 0) {
        /* ms01lte */
        property_override("ro.build.description", "ms01ltexx-user 4.4.2 KOT49H G7105XXUBNI2 release-keys");        
        set_ro_product_prop("fingerprint", "samsung/ms01ltexx/ms01lte:4.4.2/KOT49H/G7105XXUBNI2:user/release-keys");
	    gsm_properties("9", "1");
	    
    } else if (bootloader.find("G7102") == 0) {
        /* ms013g */
        property_override("ro.build.description", "ms013gxx-user 4.4.2 KOT49H G7102DDSBQF1 release-keys");        
        set_ro_product_prop("fingerprint", "samsung/ms013gxx/ms013g:4.4.2/KOT49H/G7102DDSBQF1:user/release-keys");
        gsm_properties("3", "0");
    } else {
        gsm_properties("9", "1");
    }     

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
