# Robusto/ESP-IDF/PlatformIO-dependencies
To just get going with hacking, a more logical way to create an Robusto + ESP-IDF project by adding an idf_component.yml and add it there. Then, a `managed_components`-folder would appear with all the components brought in by the ESP-IDF dependency management. 
But then we wouldn't learn much. 

# So what do we do?

Instead, this project creates a running system by using the PlatformIO-dependency management, by:
1. Create a normal PlatformIO project _(Instead yuu've cloned this)_
2. Edit the main.c _(Done)_
3. Create a folder called Components _(Done, but from here you continue)_
4. Install Robusto - Run 'pio pkg install --storage-dir ./components  --library "robusto/robusto"'
5. Click the "General->Run menuconfig" task in the PlatformIO task bar.
6. In Robusto configuration -> Memory, check "Do memory monitoring", just to have something happen.
7. Click "s" and enter to save the configuration. 
8. The `sdkconfig.az-delivery-devkit-v4` config file is created and will be used in your build.
9. Run the Upload and Monitor task. 
10. If there is an ESP32 (of any kind, probably), it will start reporting available memory.

# Why, and what does it show
Lots.
1. Because we specified `--storage-dir ./components`in step 4, the dependencies didn't end up in `.pio/libdeps/az-delivery-devkit-v4`, but in the components folder.
2. We did this, because the menuconfig implementation in PlatformIO for ESP-IDF does not include the `.pio/libdeps/az-delivery-devkit-v4` when it looks for KConfig (menu items) and KConfig.projbuild (top menu items). 
3. So if we hadn't done this, the esp_modem component would fail to build have compiled
4. This because it requires the CONFIG_ESP_MODEM_CMUX_DELAY_AFTER_DLCI_SETUP[^4] setting to be set to something. <br/>And the menuconfig application is what is generating those settings in, step 8 above. 
5. But wait, a `managed_components` folder appeared with RadioLib in it even though no PlatformIO dependency was there? <br />  That, friends is actually a mystery. Perhaps the ESP-IDF subsystem reacts to the presence of the idf_component.yml. 



[^4]: Note that menuconfig adds CONFIG_ to all defines it..defines.

