############################################################################
# apps/examples/ini_dumper/Makefile
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
############################################################################

include $(APPDIR)/Make.defs

# ini_dumper example built-in application info

PROGNAME = $(CONFIG_EXAMPLES_INI_DUMPER_PROGNAME)
PRIORITY = $(CONFIG_EXAMPLES_INI_DUMPER_PRIORITY)
STACKSIZE = $(CONFIG_EXAMPLES_INI_DUMPER_STACKSIZE)
MODULE = $(CONFIG_EXAMPLES_INI_DUMPER)

# ini_dumper Example

MAINSRC = ini_dumper_main.c

# needed to make compiler happy about wrong function pointers
# different function pointer is used depending on that define
# and that is defined in ini.h
CFLAGS += -DINI_HANDLER_LINENO=1

include $(APPDIR)/Application.mk
