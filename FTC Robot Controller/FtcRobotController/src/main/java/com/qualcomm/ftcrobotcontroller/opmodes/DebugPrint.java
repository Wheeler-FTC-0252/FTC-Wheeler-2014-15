package com.qualcomm.ftcrobotcontroller.opmodes;

import com.qualcomm.ftccommon.DbgLog;
import com.qualcomm.robotcore.eventloop.opmode.OpMode;
//import com.qualcomm.robotcore.eventloop.EventLoopManager;
//import com.qualcomm.robotcore.robocol.RobocolDatagramSocket;

/**
 * Created by lucien on 6/10/15.
 */

public class DebugPrint extends OpMode {
    public int foo = 0;
    @Override
    public void start() {
        telemetry.addData("1 Start", "**Mr. Yo takes the stand**");
        //DbgLog.msg("**Mr. Yo takes the stand**");
    }

    @Override
    public void loop() {
        telemetry.addData("2 Status", ++foo);
        //DbgLog.msg("yo");
    }

    @Override
    public void stop() {
        telemetry.addData("3 Stop", "HE HATES MY PREFORMANCE!");
        //DbgLog.msg("HE HATES MY PREFORMANCE!");
    }
}
