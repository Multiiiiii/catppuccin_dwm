/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cat                 read arbitrary file             path
 * cpu_freq            cpu frequency in MHz            NULL
 * cpu_perc            cpu usage in percent            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/)
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD/FreeBSD
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 */
static const struct arg args[] = {
	/* function format          argument */
	{ netspeed_tx, "^c#f38ba8^     [UP:%sB/s ",	 "wlp1s0"  },
	{ wifi_perc, "^c#f38ba8^ WiFi:%s%% ",       "wlp1s0"},
	{ netspeed_rx, "^c#f38ba8^ DOWN:%sB/s] ",	 "wlp1s0"  },
  { run_command, "^c#f9e2af^[%s ]", "./Suckless/Scripts/Vpn.sh"},
	{ run_command, "^c#89b4fa^[%s ",	     "./.scripts/movingbattery.sh"},
  { run_command, "^c#f9e2af^%s", "./.scripts/Batterystatus.sh"},
	{ battery_perc, "^c#89b4fa^%s%%",  "BAT0"}, 
	{ battery_remaining, "^c#89b4fa^ %s] ", "BAT0"},
	{ cpu_perc, "^c#b4befe^[^r2,8,8,8^^r0,6,2,2^^r0,16,2,2^^r10,6,2,2^^r10,16,2,2^^f20^^c#b4befe^%s%%, ",	 NULL  },
  { temp, "^c#b4befe^%s°C]", "/sys/devices/pci0000:00/0000:00:18.3/hwmon/hwmon4/temp1_input"},
  { temp, "^c#94e2d5^[%s°C]", "/sys/devices/pci0000:00/0000:00:08.1/0000:03:00.0/hwmon/hwmon3/temp1_input"},
	{ ram_perc, "^c#94e2d5^[^r0,6,3,12^^r4,6,3,12^^r8,6,3,12^^f24^%s%%] ",	 NULL  },
	{ run_command, "^c#cba6f7^[^r9,7,2,10^^r6,9,2,6^^r3,6,2,12^^r2,8,2,8^^r0,9,2,6^^f24^%s] ",	     "./.scripts/Volume.sh"},
  { run_command, "^c#eba0ac^[ %s] ",         "./.scripts/Mic.sh"},
	{ run_command, "^c#89b4fa^[🌟%s%%] ",   "./.scripts/Brightness.sh" },
	{ datetime, "^c#cba6f7^[^r0,6,1,12^^r17,6,1,12^^r1,5,16,1^^r0,9,17,1^^r1,18,16,1^^r2,11,2,2^^r6,11,2,2^^r10,11,2,2^^r14,11,2,2^^r2,15,2,2^^r6,15,2,2^^r10,15,2,2^^f24^%s",           "%F][^r0,6,1,12^^r13,6,1,12^^r1,5,12,1^^r1,18,12,1^^r6,11,1,2^^r6,7,1,4^^r7,12,4,1^^f24^%T]   "  },
};
