/*! 
\file vuser_init.c
\brief Contains vuser_init() function invoked one-time at beginning of run. 
       But we put such code in Action.c within if( iActionIterations == 1){.
Also contains declaration of app-specific global variables accessible from functions in all other action files.
*/

// Global definitions within vuser_init.c:

// VuGen files require explicit declaration of C functions that do not return integers. 
// Function prototypes below force the intepreter to save chars in read/write memory, which
// serves to avoid Error: "C interpreter runtime error - memory violation error" during replay. 
	double atof(const char *string); 
		
//// Define C Statics (like built-in LR_PASS and LR_FAIL) and variables:
	#define FOUND 0
  //	0       = FALSE/NO in C if statements
  //    1 or !0 = TRUE/YES in C if statements
	// NOTE: No semicolon after static definitions.

	#define USING_WINDOWS
	
		
	// TODO: 09. If not using VTS, comment out (substitute) # with //:
//define USE_VTS

//// Run-Time Settings Attributes or command-line LPCSTR (LoadRunner Pointer C Strings) and associated variables:

	LPCSTR			LPCSTR_HostPath; // Replaces http://127.0.0.1:1080 with {WebToursHost}

	// TODO: 08. Specify 4 during script development, then 2 during test runs.
	LPCSTR			LPCSTR_Verbosity; // used within vi_set_Verbosity_attribute() below.
	int					  iVerbosity_default = 4; 
	int 			      iVerbosity;
	                        // iVerbosity=1; to mute messages. Only wi_startPrintingError will print.
							//   2 = wi_startPrintingError and wi_startPrintingInfo will print.
							//   3 = wi_startPrintingError and wi_startPrintingInfo and wi_startPrintingDebug will print.
							//   4 = wi_startPrintingError and wi_startPrintingInfo and wi_startPrintingDebug and wi_startPrintingTrace will print.

	LPCSTR			LPCSTR_RunType; // controls scope of script generic processing (URL_Landing, SignUp, SignIn, SignOut).
	LPCSTR			LPCSTR_UseCase; // controls scope of script functional processing (add, change, delete app data).

		// For use by wi_set_Think_Time() & wi_start_transaction():
	float			floatThinkTimeSecs; // numeric.

	// For google_apis:
	LPCSTR			LPCSTR_URLSource; // 1=local .dat file, 2=VTS, 3=Google spreadsheet online?, 4=MySQL?.
	int				      iURLSource_default = 2;
	int 			      iURLSource_setting;
	// For use by vi_set_pURLtoShorten_file_recs() of local file URLtoShorten.dat:
	long			nURLtoShorten_file_recs; // counter of rows available.
	long			nURLtoShorten_index; // like i.
	int				nURLtoShorten_done; // counter of rows processed.

//// Global variables used within wi_functions.c - don't change:

	int 			iActionIterations = 0; // incremented within Action() to 
	int				isSignedIn = FALSE;
	unsigned int	original_log_option;
	char 			global_unique_id[128]=""; // included in every log output.
	int				is_msvcrt_dll_loaded = FALSE;
	int				is_kernel32_dll_loaded = FALSE;

//// Global variables referenced within WT3_ app-specific functions:

	int				iRequestRetries = 5; // maximum number of retries before giving up.
	
#ifdef  USE_VTS
	// For use by VTS within vi_set_VTS3() below.
	// TODO: 10. Follow instructions in the Getting Started Hands-on Guide to install VTS, invoke VTS, and import data into it.
	// 		Invoke VTS from Windows 7 Start > All Programs > HP Software > Virtual Table Server.
	//		This invokes "C:\Program Files (x86)\HP\LoadRunner\bin\spsConfig.hta" -launchVtsUI
	//		QUESTION: From Windows 8?
	// TODO: 11. Import data before starting this script : Start > All Programs > HP Software > HP LoadRunner > Tools > Virtual Table Server.
	LPCSTR			LPCSTR_VTS_Host;
	//char*			       VTS_Host_default="localhost"; 
	char*		           VTS_Host_string; // = LPCSTR_VTS_Host; // "localhost"; // vts1_Server; //"localhost";

	LPCSTR			LPCSTR_VTS_Port;
	//int					  nVTS_Port_default=8888;
	int				          nPort; // = int(LPCSTR_VTS_Port); // int(vts1_Port); // 4000 is installation default; // or 8888;

	int				      nVTS_row_count; // &colcount
	int				iUpdate_shorturl_in_VTS; // 1=Yes, 0=No.
#endif // USE_VTS

// WebTours-specific global variables:
	int Itineraries_count=0;

vuser_init()
{
	return 0;
}

// END SCRIPT FILE //
