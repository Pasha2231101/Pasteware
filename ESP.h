#pragma once

#include "Main.h"

namespace Client
{
	namespace Functions
	{
		namespace Visuals
		{
			struct EntityStruct
			{
				char Name[64];
				Vector vOrigin;
				int Type;
			};

			struct SoundStruct
			{
				Vector vOrigin;
				DWORD64 dwTime;
				BYTE R, G, B;
			};

			class ESP
			{
			public:

				enum FADE_COLOR
				{
					RED, LIGHT_RED, GREEN, LIGHT_GREEN, BLUE, LIGHT_BLUE, AQUAMARINE, HELIOTROPE,
					DARKPURPLEVOILET, LASERLEMON, BRIGHTGREEN, GREENLAWN, GREENYELLOWKRAYOLA, YELLOW
				};
				static void Run();
				static void RandomColor();
				static void AddSound ( DWORD64 dwTime, Vector vOrigin, BYTE R, BYTE G, BYTE B );
				static void AddEntity ( const char *Name, const Vector &vOrigin, const int &Type );
				static void ClearEntity ( );
				static void ClearSound ( );

				static void HUD_AddEntity ( cl_entity_s *Entity );
				static void HUD_Redraw ( );
				static void CL_CreateMove ( const float &frametime );


			private:
				static EntityStruct Entity[MAX_ENTITY];
				static SoundStruct Sound[MAX_SOUNDS];

				static int EntityIndex, SoundIndex;
				static BYTE BoxColor[3], FontColor[4], RandomsColor[3];

				static void PlayerFilters ( const int& Index, bool& RetFlag );
				static void SetFontColor ( );
				static float GetPlayerDistance ( const BYTE &Index, const bool &Meters );
				static void GetC4TimerValue ( );
				static void ScreenESP(const int& Index);
				static void PlayerSkeleton(const int& Index);

				static void PlayerName ( const int &Index, const int &PlayerBoxHeight, const Vector2D &ScreenTop );
				static void PlayerWeapon ( cl_entity_s *Entity, const Vector2D &ScreenBot, const Vector2D &ScreenTop );
				static void PlayerDistance ( const int &Index, const Vector2D &ScreenBot, const Vector2D &ScreenTop );

				static void WorldNades ( const int &Index, const Vector2D &EntityScreen );
				static void WorldWeapons ( const int& Index, const Vector2D& EntityScreen, const char* Weapon );
				static void WorldC4 ( const int& Index, const Vector2D& EntityScreen );
				static void WorldC4Planted ( const int& Index, const Vector2D& EntityScreen );
				static void PenetrationInfo();
				static void DrawPlayer(cl_entity_s* Entity, int iIndex);
				static void DrawWorld ( );
				static void DrawC4Timer ( );
				static void DrawSound ( );
			};
		}
	}
}