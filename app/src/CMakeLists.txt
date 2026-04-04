
add_executable(${NAME}
        main.cpp
        ui/ClockScreen.cpp
        ui/ConfigScreen.cpp
        ui/CommandsScreen.cpp
        ui/App.cpp
        ui/widgets/StyledButton.cpp
        assets/img/clockface_bg_rp2350_dark.c
        assets/img/seconds_hand_rp2350_dark.c
        assets/img/minutes_hand_rp2350_dark.c
        assets/img/hours_hand_rp2350_dark.c
        assets/fonts/din_cond_medium_regular_num_96.c
        assets/fonts/din_cond_medium_regular_num_72.c
        assets/fonts/din_cond_medium_regular_20.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} 
	pico_stdlib
	bsp
        lvgl
	)

   
# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# enable usb output, disable uart output
pico_enable_stdio_usb(${NAME} 1)
pico_enable_stdio_uart(${NAME} 0)
