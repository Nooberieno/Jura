#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "include/UserConfig.h"
#include "include/syntax_highlighting.h"

UserConfig UConfig;

void DefaultConfig(void){ //Sets the default config
	char config_path[256];
	char* XDG = getenv("XDG_CONFIG_HOME");
	if(XDG == NULL){
		char* home_dir = getenv("HOME");
		strcpy(config_path, home_dir);
    	strcat(config_path, "/.config/config.jura");
	}else{
		strcpy(config_path, XDG);
		strcat(config_path, "/config.jura");
	} 
	FILE *file = fopen(config_path, "w");
	fprintf(file, "%d\n%d\n%d\n%d\n%d\n%d\n%s", 36, 33, 34, 31, 35, 32, "-");
	fclose(file);
}

void SaveConfig(struct UserConfig *config, char *filename){ //Saves the config container to the config file
	FILE *file = fopen(filename, "w");
	fprintf(file, "%d\n%d\n%d\n%d\n%d\n%d\n%s", config->Comment_Color, config->Keywords_Color, config->Types_Color, config->StringColor_, config->Number_Color, config->Match_Color, config->First_Char);
	fclose(file);
}

void LoadConfig(struct UserConfig *config, char *filename){ //Loads a config file to the config container
	FILE *file = fopen(filename, "r");
	if(file != NULL){
		if(fscanf(file, "%d\n%d\n%d\n%d\n%d\n%d\n%s", &config->Comment_Color, &config->Keywords_Color, &config->Types_Color, &config->StringColor_, &config->Number_Color, &config->Match_Color, config->First_Char) != 7){
			fprintf(stderr, "Failed to scan config file for values");
			config->Comment_Color = 36;
			config->Keywords_Color = 33;
			config->Types_Color = 34;
			config->StringColor_ = 31;
			config->Number_Color = 35;
			config->Types_Color = 32;
			strcpy(config->First_Char, "-");
		}
		fclose(file);
	}else{ 
		DefaultConfig();
		char *home_dir = getenv("HOME");
		char config_path[256];
		strcpy(config_path, home_dir);
    	strcat(config_path, "/.config/config.jura");
		FILE *file = fopen(config_path, "r");
if(fscanf(file, "%d\n%d\n%d\n%d\n%d\n%d\n%s", &config->Comment_Color, &config->Keywords_Color, &config->Types_Color, &config->StringColor_, &config->Number_Color, &config->Match_Color, config->First_Char) != 7){
			fprintf(stderr, "Failed to scan config file for values");
			config->Comment_Color = 36;
			config->Keywords_Color = 33;
			config->Types_Color = 34;
			config->StringColor_ = 31;
			config->Number_Color = 35;
			config->Types_Color = 32;
			strcpy(config->First_Char, "-");
		}		
		fclose(file);
	}
}

int SyntaxToColor(int hl){
	switch(hl){
		case Comment:
		case MultiLineComment: return UConfig.Comment_Color;
		case Keywords: return UConfig.Keywords_Color;
		case Types: return UConfig.Types_Color;
		case StringColor: return UConfig.StringColor_;
		case Number: return UConfig.Number_Color;
		case Match: return UConfig.Match_Color;
		default: return 37;
	}
}
