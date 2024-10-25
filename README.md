In this lab, we used oscilliscopes to measure the accuracy of frequency for different executable files.

Then we added a busy loop to each file and measured the new accuracy.

Our observations are summarized here:

                    expected time |   Actual time  |   percent error
reference               5 Hz      |   4.99993 Hz      |   1.4 E -5
sleep before busy loop   200 ms |   199.9988 ms |   6.0 E - 6
sleep after busy loop   272 ms  |    271.998 ms |   7.3529 E - 6

task delay before       200 ms  |   199.998     |   1 E -5
task delay after        272 ms  |    271.998 ms |   7.3529 E - 6

timer before            200 ms  |   199.998     |   1 E -5
timer after             the code breaks and is unobservable on the oscilliscope

interrupt request before    200 ms  |   199.998     |   1 E -5
interrupt request after     the code breaks and is unobservable on the oscilliscope




