// -*- c++ -*-
// $Id$
/*
 * Copyright 2005 Spencer Olson
 *
 * $Log$
 *
 */


#include "oct-Field.h"
#include <octave/oct.h>
#include <octave/pager.h>

DEFUN_DLD (LPSuperGaussAperture, args, nargout,
"LPSuperGaussAperture\n"
"****************************************************************************************************\n"
"\n"
"	LightPipes for Octave Optical Toolbox\n"
"\n"
"	LPSuperGaussAperture apertures the field with a Gaussian aperture.\n"
"\n"
"	USAGE:\n"
"	Fout=LPSuperGaussAperture(w,n,x0,y0,R,Fin);\n"
"\n"
"	with:\n"
"	w                = 1/e intensity width of the aperture\n"
"       n                = order of super gaussian\n"
"	x0, y0           = displacement from the center\n"
"	T                = transmission coefficient through the aperture\n"
"	Fin              = the input field struct (see LPBegin)\n"
"	Fout             = the output field struct (see LPBegin)\n"
"\n"
"****************************************************************************************************\n"
) {
    if (args.length() != 6 ||
        !args(0).is_real_scalar() ||
        !args(1).is_real_scalar() ||
        !args(2).is_real_scalar() ||
        !args(3).is_real_scalar() ||
        !args(4).is_real_scalar() ||
        !args(5).is_map() || !mapIsValidField(octave_stdout, args(5).map_value())
        ) {
        if ( args.length() >= 1 && !args(0).is_real_scalar() ) octave_stdout << "arg 0 is invalid" << std::endl;
        if ( args.length() >= 2 && !args(1).is_real_scalar() ) octave_stdout << "arg 1 is invalid" << std::endl;
        if ( args.length() >= 3 && !args(2).is_real_scalar() ) octave_stdout << "arg 2 is invalid" << std::endl;
        if ( args.length() >= 4 && !args(3).is_real_scalar() ) octave_stdout << "arg 3 is invalid" << std::endl;
        if ( args.length() >= 5 && !args(4).is_real_scalar() ) octave_stdout << "arg 4 is invalid" << std::endl;

        print_usage("LPSuperGaussAperture");
        return octave_value();
    }

    double w   = args(0).double_value();
    int    n   = args(1).int_value();
    double x0  = args(2).double_value();
    double y0  = args(3).double_value();
    double T   = args(4).double_value();
    Field * field = mapToField( args(5).map_value() );
    field->supergaussian_aperture(w, n, x0, y0, T);
    octave_value retval(fieldToMap(*field));
    delete field;       field = NULL;

    return retval;
}

