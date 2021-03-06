# Include this script only after using shutdown_mysqld.inc
# where $_expect_file_name was initialized.
# Write file to make mysql-test-run.pl start up the server again
if ($restart_parameters)
{
  --exec echo "restart: $restart_parameters" > $_expect_file_name
}
if (!$restart_parameters)
{
  --exec echo "restart" > $_expect_file_name
}

# Turn on reconnect
--enable_reconnect

# Call script that will poll the server waiting for it to be back online again
--source include/wait_until_connected_again.inc

# Wait for wsrep
--source include/wait_wsrep_ready.inc

# Turn off reconnect again
--disable_reconnect

