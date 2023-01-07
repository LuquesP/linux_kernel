cmd_/home/lukas/source/linux_kernel/hello/modules.order := {   echo /home/lukas/source/linux_kernel/hello/hello.ko; :; } | awk '!x[$$0]++' - > /home/lukas/source/linux_kernel/hello/modules.order
