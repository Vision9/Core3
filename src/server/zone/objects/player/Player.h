/*
 *	server/zone/objects/player/Player.h generated by engine3 IDL compiler 0.55
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/service/proto/BaseMessage.h"

#include "engine/service/proto/StandaloneBaseMessage.h"

#include "../../packets/object/StfParameter.h"

#include "professions/SkillBox.h"

class ZoneClientSession;

class Zone;

class SceneObject;

class CreatureObject;

class Creature;

class TangibleObject;

class PlayerObject;

class FactionPointList;

class Weapon;

class Armor;

class Attachment;

class Powerup;

class Datapad;

class SurveyTool;

class GroupObject;

class Guild;

class WaypointObject;

class ChatRoom;

class SuiBox;

class SuiListBoxVector;

class DraftSchematic;

class CraftingTool;

class ResourceContainer;

class Badges;

class ActiveArea;

#include "../creature/CreatureObject.h"

class Player : public CreatureObject {
public:
	Player();

	Player(unsigned long long oid);

	void initialize();

	void create(ZoneClientSession* client);

	void refuseCreate(ZoneClientSession* client);

	void load(ZoneClientSession* client);

	void reload(ZoneClientSession* client);

	void unload();

	void savePlayerState(bool doSchedule = false);

	void disconnect(bool closeClient = true, bool doLock = true);

	void logout(bool doLock = true);

	void userLogout(int msgCounter = 3);

	void resurrectCountdown(int counter = 6);

	void clearLogoutEvent();

	void clearResurrectEvent();

	void clearDigestEvent();

	void clearRecoveryEvent();

	void clearSaveStateEvent();

	void makeCharacterMask();

	unsigned int getCharacterMask();

	void insertToZone(Zone* zone);

	void reinsertToZone(Zone* zone);

	void updateZone(bool lightUpdate = false);

	void updateZoneWithParent(unsigned long long cell, bool lightUpdate = false);

	void switchMap(int planetid);

	void doWarp(float x, float y, float z = 0, float randomizeDistance = 0, unsigned long long parentID = 0);

	void bounceBack();

	void sendTo(Player* player);

	void sendToOwner();

	void notifySceneReady();

	void addDatapadItem(SceneObject* item);

	SceneObject* getDatapadItem(unsigned long long oid);

	void removeDatapadItem(unsigned long long oid);

	SceneObject* getPlayerItem(unsigned long long oid);

	unsigned int getTargetHealth();

	unsigned int getTargetStrength();

	unsigned int getTargetConstitution();

	unsigned int getTargetAction();

	unsigned int getTargetQuickness();

	unsigned int getTargetStamina();

	unsigned int getTargetMind();

	unsigned int getTargetFocus();

	unsigned int getTargetWillpower();

	void setTargetHealth(unsigned int health);

	void setTargetStrength(unsigned int strength);

	void setTargetConstitution(unsigned int constituition);

	void setTargetAction(unsigned int action);

	void setTargetQuickness(unsigned int quickness);

	void setTargetStamina(unsigned int stamina);

	void setTargetMind(unsigned int mind);

	void setTargetFocus(unsigned int focus);

	void setTargetWillpower(unsigned int willpower);

	unsigned int getMinHealth();

	unsigned int getMaxHealth();

	unsigned int getMinStrength();

	unsigned int getMaxStrength();

	unsigned int getMinConstitution();

	unsigned int getMaxConstitution();

	unsigned int getMinAction();

	unsigned int getMaxAction();

	unsigned int getMinQuickness();

	unsigned int getMaxQuickness();

	unsigned int getMinStamina();

	unsigned int getMaxStamina();

	unsigned int getMinMind();

	unsigned int getMaxMind();

	unsigned int getMinFocus();

	unsigned int getMaxFocus();

	unsigned int getMinWillpower();

	unsigned int getMaxWillpower();

	unsigned int getTotalAttribPoints();

	void queueFlourish(const String& modifier, unsigned long long target, unsigned int actionCntr);

	void clearQueueAction(unsigned int actioncntr, float timer = 0, unsigned int tab1 = 0, unsigned int tab2 = 0);

	void queueAction(Player* player, unsigned long long target, unsigned int actionCRC, unsigned int actionCntr, const String& actionModifier);

	void deleteQueueAction(unsigned int actioncntr);

	void changePosture(int post);

	void doCenterOfBeing();

	void removeCenterOfBeing();

	bool doPowerboost();

	void doPeace();

	void kill();

	void deathblow(Player* player);

	void resurrect();

	void handleDeath();

	void throttlePvpRating(Player* player);

	void doClone();

	void activateClone();

	void doRecovery();

	void doDigest();

	bool hasConsent(String& charID);

	bool giveConsent(String& name);

	bool revokeConsent(String& name);

	int getConsentSize();

	String& getConsentEntry(int index);

	Badges* getBadges();

	void sendConsentBox();

	void addBuff(unsigned int buffcrc, float time);

	void lootCorpse(bool lootAll = false);

	void lootObject(Creature* creature, SceneObject* object);

	void addTradeItem(TangibleObject* item);

	void clearTradeItems();

	int getTradeSize();

	TangibleObject* getTradeItem(int idx);

	void setAcceptedTrade(bool val);

	bool hasAcceptedTrade();

	void setVerifiedTrade(bool val);

	bool hasVerifiedTrade();

	void setMoneyToTrade(unsigned int value);

	unsigned int getMoneyToTrade();

	bool getMeditate();

	bool getPowerboosted();

	void setPowerboosted(bool pb);

	void changeCloth(unsigned long long itemid);

	void changeWeapon(unsigned long long itemid, bool doUpdate);

	void changeArmor(unsigned long long itemid, bool forced);

	void setWeaponSkillMods(Weapon* weapon);

	void setArmorSkillMods(Armor* armor);

	bool setArmorEncumbrance(Armor* armor, bool forced);

	void unsetArmorEncumbrance(Armor* armor);

	void applyAttachment(unsigned long long attachmentID, unsigned long long targetID);

	void applyPowerup(unsigned long long powerupID, unsigned long long targetID);

	void loadItems(bool newcharacter);

	void createBaseStats();

	void decayInventory();

	bool hasFullInventory();

	void addInventoryItem(TangibleObject* item);

	void addInventoryResource(ResourceContainer* item);

	void equipPlayerItem(TangibleObject* item, bool doUpdate);

	void saveDatapad(Player* player);

	void saveProfessions();

	void loadProfessions();

	void trainStartingProfession();

	bool trainSkillBox(const String& name, bool updateClient = true);

	void surrenderSkillBox(const String& name);

	void resetSkillBoxesIterator();

	int getSkillBoxesSize();

	String& getNextSkillBox();

	bool hasNextSkillBox();

	bool hasSkillBox(String& skillBox);

	void startForaging(int foragetype);

	bool isForaging();

	int lottery(int mytickets, int totaltickets);

	void addWaypoint(WaypointObject* wp);

	bool removeWaypoint(WaypointObject* wp);

	WaypointObject* getWaypoint(unsigned long long id);

	void updateWaypoint(WaypointObject* wp);

	void saveWaypoints(Player* player);

	WaypointObject* searchWaypoint(Player* play, const String& name, int mode);

	void queueHeal(TangibleObject* medpack, unsigned int actionCRC, const String& attribute);

	int getXp(const String& xpType);

	void addXp(String& xpType, int xp, bool updateClient);

	void removeXp(String& xpType, int xp, bool updateClient);

	void loadXp(const String& xpStr);

	String& saveXp();

	int getXpTypeCap(String& xptype);

	void loadXpTypeCap();

	int calcPlayerLevel(String& xptype);

	void removeFromDuelList(Player* targetPlayer);

	void addToDuelList(Player* targetPlayer);

	bool isInDuelWith(Player* targetPlayer, bool doLock = true);

	Player* getDuelListObject(int index);

	bool requestedDuelTo(Player* targetPlayer);

	bool isDuelListEmpty();

	int getDuelListSize();

	bool setGuild(unsigned int gid);

	void setGuild(Guild* gild);

	bool updateGuild(unsigned int gid);

	void updateGuild(Guild* guild);

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

	void sendSystemMessage(const String& msg);

	void sendSystemMessage(UnicodeString& msg);

	void sendSystemMessage(const String& file, const String& str, unsigned long long targetid = 0);

	void sendSystemMessage(const String& file, const String& str, StfParameter* param);

	void sendBattleFatigueMessage(CreatureObject* target);

	void sendHealMessage(CreatureObject* target, int h, int a, int m);

	void setConversatingCreature(CreatureObject* conversator);

	void setFirstName(const String& name);

	void setLastName(const String& name);

	void setFirstNameProper(const String& name);

	void setBiography(const String& bio);

	void setBiography(UnicodeString& bio);

	bool changeForcePowerBar(int fp);

	void setForcePowerBar(int fp);

	void updateMaxForcePowerBar(bool updateClient = true);

	void setFoodFilling(int fill, bool updateClient = true);

	void setDrinkFilling(int fill, bool updateClient = true);

	void changeFoodFilling(int fill, bool updateClient = true);

	void changeDrinkFilling(int fill, bool updateClient = true);

	bool isAttackableBy(CreatureObject* attacker);

	int getFoodFilling();

	int getDrinkFilling();

	void activateDigest();

	void activateQueueAction();

	void setCharacterID(unsigned long long id);

	void setStartingProfession(const String& prof);

	void setHairObject(const String& hair);

	void updateHair();

	void setPlayerObject(PlayerObject* obj);

	void setOnline();

	void clearDisconnectEvent();

	void setClient(ZoneClientSession* client);

	void updateNextTipTime();

	bool canTip();

	void setOvert();

	void setCovert();

	void setOnLeave();

	bool isOvert();

	bool isCovert();

	bool isOnLeave();

	void newChangeFactionStatusEvent(unsigned char status, unsigned int timer);

	void setRaceFileName(String& name);

	void setRaceID(unsigned char id);

	void setStartingLocation(String& loc);

	void setItemShift(unsigned int shift);

	void toggleCharacterBit(unsigned int bit);

	void awardBadge(unsigned char badge);

	void removeBadge(unsigned char badge);

	bool hasBadge(unsigned char badge);

	void setLinkDead();

	void setLoggingIn();

	void setAdminLevel(int level);

	int getAdminLevel();

	void setLastTestPositionX(float pos);

	void setLastTestPositionY(float pos);

	void setTradeRequestedPlayer(unsigned long long ID);

	unsigned long long getTradeRequestedPlayer();

	void launchFirework(int anim);

	void sendMessage(BaseMessage* msg);

	void sendMessage(StandaloneBaseMessage* msg);

	void broadcastMessageToOthersAround(Player* player, BaseMessage* msg);

	bool isJedi();

	void mutePlayer();

	void toggleImmune();

	bool hasSuiBox(unsigned int boxID);

	bool hasSuiBoxType(unsigned int boxTypeID);

	unsigned int getSuiBoxFromType(unsigned int boxTypeID);

	void removeSuiBox(unsigned int boxID);

	SuiBox* getSuiBox(unsigned int boxID);

	void addSuiBox(SuiBox* sui);

	unsigned int getNewSuiBoxID(unsigned int type);

	bool isOnline();

	bool isOffline();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	bool isLoading();

	PlayerObject* getPlayerObject();

	CreatureObject* getConversatingCreature();

	String& getFirstName();

	String& getLastName();

	String& getFirstNameProper();

	String& getRaceFileName();

	unsigned char getRaceID();

	UnicodeString& getBiography();

	unsigned long long getCharacterID();

	String& getStartingProfession();

	int getZoneIndex();

	String& getHairObject();

	ZoneClientSession* getClient();

	GroupObject* getGroupObject();

	int getPvpRating();

	void setPvpRating(int value);

	void increasePvpRating(int value);

	void decreasePvpRating(int value);

	void getPlayersNearYou();

	int getRegionID();

	int getCertificationListSize();

	String& getCertification(int idx);

	bool checkCertification(String& certification);

	int getSlicingAbility();

	bool isChatMuted();

	bool isImmune();

	String& getInputBoxReturnBuffer();

	unsigned int nextMisoRFC();

	int checkMisoBSB(int tcb);

	void setMisoBSB(int tms);

	void addToCurMisoKeys(String& tck);

	bool isOnCurMisoKey(String& tmk);

	void removeFromCurMisoKeys(String& tck);

	void addToFinMisoKeys(String& tmp);

	bool hasCompletedMisoKey(String& tmk);

	void updateMissionSave(String& misoKey, const String& dbVar, String& varName, String& varData, bool doLock = false);

	void fillMissionSaveVars();

	void saveMissions();

	CraftingTool* getCurrentCraftingTool();

	CraftingTool* getCraftingTool(const int type, bool doLock = true);

	void setCurrentCraftingTool(CraftingTool* ct);

	void clearCurrentCraftingTool();

	void prepareCraftingSession(CraftingTool* ct, DraftSchematic* ds);

	void addIngredientToSlot(TangibleObject* tano, int slot, int counter);

	void removeResourceFromCraft(unsigned long long resID, int slot, int counter);

	void nextCraftingStage(String& test);

	void craftingCustomization(String& name, int condition, String& customizationString);

	void createPrototype(String& count);

	void createSchematic(String& count);

	void handleExperimenting(int count, int numRowsAttempted, String& expString);

	void sendDraftSchematics();

	void addDraftSchematicsFromGroupName(const String& schematicGroupName);

	void subtractDraftSchematicsFromGroupName(const String& schematicGroupName);

	void addDraftSchematic(DraftSchematic* ds);

	void subtractDraftSchematic(DraftSchematic* ds);

	unsigned int getDraftSchematicListSize();

	unsigned int getDraftSchematicUpdateCount(unsigned int count);

	DraftSchematic* getDraftSchematic(unsigned int schematicID);

	DraftSchematic* getDraftSchematic(int index);

	bool isChangingFactionStatus();

	Datapad* getDatapad();

	unsigned long long getNewItemID();

	unsigned int getItemShift();

	float getLastTestPositionX();

	float getLastTestPositionY();

	unsigned int getForcePower();

	unsigned int getForcePowerMax();

	bool isGuildLeader();

	unsigned long long getCurrentStructureID();

	void setCurrentStructureID(unsigned long long oid);

	SurveyTool* getSurveyTool();

	SurveyTool* getSampleTool();

	void setSurveyTool(SurveyTool* sTool);

	void setSampleTool(SurveyTool* sTool);

	void setSurveyWaypoint(WaypointObject* id);

	WaypointObject* getSurveyWaypoint();

	bool getCanSurvey();

	bool getCanSample();

	void setCanSurvey();

	void setCanSample();

	void clearFirstSampleEvent();

	void setSurveyEvent(String& resourcename);

	void setSampleEvent(String& resourcename, bool firstTime = false);

	void setCancelSample(bool val);

	bool getCancelSample();

	void sendSampleTimeRemaining();

	void setSurveyErrorMessage();

	void setSampleErrorMessage();

	bool getSurveyErrorMessage();

	bool getSampleErrorMessage();

	void sendMail(String& mailsender, UnicodeString& subjectSender, UnicodeString& bodySender, String& charNameSender);

	void setEntertainerEvent();

	void clearEntertainerEvent();

	void addEntertainerFlourishXp(int xp);

	void addEntertainerHealingXp(int xp);

	void setLastNpcConvStr(const String& conv);

	void setLastNpcConvMessStr(const String& mess);

	String& getLastNpcConvStr();

	String& getLastNpcConvMessStr();

	String& getLastNpcConvOption(int idx);

	void addLastNpcConvOptions(const String& option);

	void clearLastNpcConvOptions();

	int countLastNpcConvOptions();

	void setInputBoxReturnBuffer(const String& message);

	void setGuildLeader(bool guildLeader = true);

	void loadGuildChat();

	void setGuildPermissions(unsigned int bit);

	unsigned int getGuildPermissions();

	bool setGuildPermissionsBit(unsigned int bit, bool updateClient = false);

	void toggleGuildPermissionsBit(unsigned int bit);

	bool clearGuildPermissionsBit(unsigned int bit, bool updateClient = false);

	int getFactionPoints(const String& faction);

	void addFactionPoints(const String& faction, unsigned int points);

	void subtractFactionPoints(const String& faction, unsigned int points);

	int getFactionStatus();

	void setFactionStatus(int status);

	FactionPointList* getFactionList();

	unsigned int getMaxFactionPoints(String& faction);

	void delFactionPoints(Player* player, unsigned int amount);

	void updateWeather();

	void addSuiBoxChoice(String& choice);

	void removeLastSuiBoxChoice();

	void setSuiBoxChoices(SuiListBoxVector* choicesList);

	SuiListBoxVector* getSuiBoxChoices();

	void clearSuiBoxChoices();

	void setResourceDeedID(unsigned long long objectID);

	unsigned long long getResourceDeedID();

	void queueThrow(TangibleObject* throwItem, unsigned int actionCRC);

	void setImagedesignXpGiven(bool given);

	bool getImagedesignXpGiven();

	void teachPlayer(Player* player);

	void setTeachingOffer(String& sBox);

	void setTeacher(Player* player);

	void setStudent(Player* player);

	String& getTeachingOffer();

	Player* getTeacher();

	Player* getStudent();

	String& getTeachingSkillOption(int idx);

	void clearTeachingSkillOptions();

	void teachSkill(String& skillname);

	ActiveArea* getActiveArea();

	void setActiveArea(ActiveArea* area);

	void equipItem(TangibleObject* item);

	void unequipItem(TangibleObject* item);

	Armor* getPlayerArmor(int location);

protected:
	Player(DummyConstructorParameter* param);

	virtual ~Player();

	String _return_getCertification;
	String _return_getConsentEntry;
	String _return_getFirstName;
	String _return_getFirstNameProper;
	String _return_getHairObject;
	String _return_getInputBoxReturnBuffer;
	String _return_getLastName;
	String _return_getLastNpcConvMessStr;
	String _return_getLastNpcConvOption;
	String _return_getLastNpcConvStr;
	String _return_getNextSkillBox;
	String _return_getRaceFileName;
	String _return_getStartingProfession;
	String _return_getTeachingOffer;
	String _return_getTeachingSkillOption;
	String _return_saveXp;

	UnicodeString _return_getBiography;

	friend class PlayerHelper;
};

class PlayerImplementation;

class PlayerAdapter : public CreatureObjectAdapter {
public:
	PlayerAdapter(PlayerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initialize();

	void create(ZoneClientSession* client);

	void refuseCreate(ZoneClientSession* client);

	void load(ZoneClientSession* client);

	void reload(ZoneClientSession* client);

	void unload();

	void savePlayerState(bool doSchedule);

	void disconnect(bool closeClient, bool doLock);

	void logout(bool doLock);

	void userLogout(int msgCounter);

	void resurrectCountdown(int counter);

	void clearLogoutEvent();

	void clearResurrectEvent();

	void clearDigestEvent();

	void clearRecoveryEvent();

	void clearSaveStateEvent();

	void makeCharacterMask();

	unsigned int getCharacterMask();

	void insertToZone(Zone* zone);

	void reinsertToZone(Zone* zone);

	void updateZone(bool lightUpdate);

	void updateZoneWithParent(unsigned long long cell, bool lightUpdate);

	void switchMap(int planetid);

	void doWarp(float x, float y, float z, float randomizeDistance, unsigned long long parentID);

	void bounceBack();

	void sendTo(Player* player);

	void sendToOwner();

	void notifySceneReady();

	void addDatapadItem(SceneObject* item);

	SceneObject* getDatapadItem(unsigned long long oid);

	void removeDatapadItem(unsigned long long oid);

	SceneObject* getPlayerItem(unsigned long long oid);

	unsigned int getTargetHealth();

	unsigned int getTargetStrength();

	unsigned int getTargetConstitution();

	unsigned int getTargetAction();

	unsigned int getTargetQuickness();

	unsigned int getTargetStamina();

	unsigned int getTargetMind();

	unsigned int getTargetFocus();

	unsigned int getTargetWillpower();

	void setTargetHealth(unsigned int health);

	void setTargetStrength(unsigned int strength);

	void setTargetConstitution(unsigned int constituition);

	void setTargetAction(unsigned int action);

	void setTargetQuickness(unsigned int quickness);

	void setTargetStamina(unsigned int stamina);

	void setTargetMind(unsigned int mind);

	void setTargetFocus(unsigned int focus);

	void setTargetWillpower(unsigned int willpower);

	unsigned int getMinHealth();

	unsigned int getMaxHealth();

	unsigned int getMinStrength();

	unsigned int getMaxStrength();

	unsigned int getMinConstitution();

	unsigned int getMaxConstitution();

	unsigned int getMinAction();

	unsigned int getMaxAction();

	unsigned int getMinQuickness();

	unsigned int getMaxQuickness();

	unsigned int getMinStamina();

	unsigned int getMaxStamina();

	unsigned int getMinMind();

	unsigned int getMaxMind();

	unsigned int getMinFocus();

	unsigned int getMaxFocus();

	unsigned int getMinWillpower();

	unsigned int getMaxWillpower();

	unsigned int getTotalAttribPoints();

	void queueFlourish(const String& modifier, unsigned long long target, unsigned int actionCntr);

	void clearQueueAction(unsigned int actioncntr, float timer, unsigned int tab1, unsigned int tab2);

	void queueAction(Player* player, unsigned long long target, unsigned int actionCRC, unsigned int actionCntr, const String& actionModifier);

	void deleteQueueAction(unsigned int actioncntr);

	void changePosture(int post);

	void doCenterOfBeing();

	void removeCenterOfBeing();

	bool doPowerboost();

	void doPeace();

	void kill();

	void deathblow(Player* player);

	void resurrect();

	void handleDeath();

	void throttlePvpRating(Player* player);

	void doClone();

	void activateClone();

	void doRecovery();

	void doDigest();

	bool hasConsent(String& charID);

	bool giveConsent(String& name);

	bool revokeConsent(String& name);

	int getConsentSize();

	String& getConsentEntry(int index);

	Badges* getBadges();

	void sendConsentBox();

	void addBuff(unsigned int buffcrc, float time);

	void lootCorpse(bool lootAll);

	void lootObject(Creature* creature, SceneObject* object);

	void addTradeItem(TangibleObject* item);

	void clearTradeItems();

	int getTradeSize();

	TangibleObject* getTradeItem(int idx);

	void setAcceptedTrade(bool val);

	bool hasAcceptedTrade();

	void setVerifiedTrade(bool val);

	bool hasVerifiedTrade();

	void setMoneyToTrade(unsigned int value);

	unsigned int getMoneyToTrade();

	bool getMeditate();

	bool getPowerboosted();

	void setPowerboosted(bool pb);

	void changeCloth(unsigned long long itemid);

	void changeWeapon(unsigned long long itemid, bool doUpdate);

	void changeArmor(unsigned long long itemid, bool forced);

	void setWeaponSkillMods(Weapon* weapon);

	void setArmorSkillMods(Armor* armor);

	bool setArmorEncumbrance(Armor* armor, bool forced);

	void unsetArmorEncumbrance(Armor* armor);

	void applyAttachment(unsigned long long attachmentID, unsigned long long targetID);

	void applyPowerup(unsigned long long powerupID, unsigned long long targetID);

	void loadItems(bool newcharacter);

	void createBaseStats();

	void decayInventory();

	bool hasFullInventory();

	void addInventoryItem(TangibleObject* item);

	void addInventoryResource(ResourceContainer* item);

	void equipPlayerItem(TangibleObject* item, bool doUpdate);

	void saveDatapad(Player* player);

	void saveProfessions();

	void loadProfessions();

	void trainStartingProfession();

	bool trainSkillBox(const String& name, bool updateClient);

	void surrenderSkillBox(const String& name);

	void resetSkillBoxesIterator();

	int getSkillBoxesSize();

	String& getNextSkillBox();

	bool hasNextSkillBox();

	bool hasSkillBox(String& skillBox);

	void startForaging(int foragetype);

	bool isForaging();

	int lottery(int mytickets, int totaltickets);

	void addWaypoint(WaypointObject* wp);

	bool removeWaypoint(WaypointObject* wp);

	WaypointObject* getWaypoint(unsigned long long id);

	void updateWaypoint(WaypointObject* wp);

	void saveWaypoints(Player* player);

	WaypointObject* searchWaypoint(Player* play, const String& name, int mode);

	void queueHeal(TangibleObject* medpack, unsigned int actionCRC, const String& attribute);

	int getXp(const String& xpType);

	void addXp(String& xpType, int xp, bool updateClient);

	void removeXp(String& xpType, int xp, bool updateClient);

	void loadXp(const String& xpStr);

	String& saveXp();

	int getXpTypeCap(String& xptype);

	void loadXpTypeCap();

	int calcPlayerLevel(String& xptype);

	void removeFromDuelList(Player* targetPlayer);

	void addToDuelList(Player* targetPlayer);

	bool isInDuelWith(Player* targetPlayer, bool doLock);

	Player* getDuelListObject(int index);

	bool requestedDuelTo(Player* targetPlayer);

	bool isDuelListEmpty();

	int getDuelListSize();

	bool setGuild(unsigned int gid);

	void setGuild(Guild* gild);

	bool updateGuild(unsigned int gid);

	void updateGuild(Guild* guild);

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

	void sendSystemMessage(const String& msg);

	void sendSystemMessage(UnicodeString& msg);

	void sendSystemMessage(const String& file, const String& str, unsigned long long targetid);

	void sendSystemMessage(const String& file, const String& str, StfParameter* param);

	void sendBattleFatigueMessage(CreatureObject* target);

	void sendHealMessage(CreatureObject* target, int h, int a, int m);

	void setConversatingCreature(CreatureObject* conversator);

	void setFirstName(const String& name);

	void setLastName(const String& name);

	void setFirstNameProper(const String& name);

	void setBiography(const String& bio);

	void setBiography(UnicodeString& bio);

	bool changeForcePowerBar(int fp);

	void setForcePowerBar(int fp);

	void updateMaxForcePowerBar(bool updateClient);

	void setFoodFilling(int fill, bool updateClient);

	void setDrinkFilling(int fill, bool updateClient);

	void changeFoodFilling(int fill, bool updateClient);

	void changeDrinkFilling(int fill, bool updateClient);

	bool isAttackableBy(CreatureObject* attacker);

	int getFoodFilling();

	int getDrinkFilling();

	void activateDigest();

	void activateQueueAction();

	void setCharacterID(unsigned long long id);

	void setStartingProfession(const String& prof);

	void setHairObject(const String& hair);

	void updateHair();

	void setPlayerObject(PlayerObject* obj);

	void setOnline();

	void clearDisconnectEvent();

	void setClient(ZoneClientSession* client);

	void updateNextTipTime();

	bool canTip();

	void setOvert();

	void setCovert();

	void setOnLeave();

	bool isOvert();

	bool isCovert();

	bool isOnLeave();

	void newChangeFactionStatusEvent(unsigned char status, unsigned int timer);

	void setRaceFileName(String& name);

	void setRaceID(unsigned char id);

	void setStartingLocation(String& loc);

	void setItemShift(unsigned int shift);

	void toggleCharacterBit(unsigned int bit);

	void awardBadge(unsigned char badge);

	void removeBadge(unsigned char badge);

	bool hasBadge(unsigned char badge);

	void setLinkDead();

	void setLoggingIn();

	void setAdminLevel(int level);

	int getAdminLevel();

	void setLastTestPositionX(float pos);

	void setLastTestPositionY(float pos);

	void setTradeRequestedPlayer(unsigned long long ID);

	unsigned long long getTradeRequestedPlayer();

	void launchFirework(int anim);

	void sendMessage(BaseMessage* msg);

	void sendMessage(StandaloneBaseMessage* msg);

	void broadcastMessageToOthersAround(Player* player, BaseMessage* msg);

	bool isJedi();

	void mutePlayer();

	void toggleImmune();

	bool hasSuiBox(unsigned int boxID);

	bool hasSuiBoxType(unsigned int boxTypeID);

	unsigned int getSuiBoxFromType(unsigned int boxTypeID);

	void removeSuiBox(unsigned int boxID);

	SuiBox* getSuiBox(unsigned int boxID);

	void addSuiBox(SuiBox* sui);

	unsigned int getNewSuiBoxID(unsigned int type);

	bool isOnline();

	bool isOffline();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	bool isLoading();

	PlayerObject* getPlayerObject();

	CreatureObject* getConversatingCreature();

	String& getFirstName();

	String& getLastName();

	String& getFirstNameProper();

	String& getRaceFileName();

	unsigned char getRaceID();

	UnicodeString& getBiography();

	unsigned long long getCharacterID();

	String& getStartingProfession();

	int getZoneIndex();

	String& getHairObject();

	ZoneClientSession* getClient();

	GroupObject* getGroupObject();

	int getPvpRating();

	void setPvpRating(int value);

	void increasePvpRating(int value);

	void decreasePvpRating(int value);

	void getPlayersNearYou();

	int getRegionID();

	int getCertificationListSize();

	String& getCertification(int idx);

	bool checkCertification(String& certification);

	int getSlicingAbility();

	bool isChatMuted();

	bool isImmune();

	String& getInputBoxReturnBuffer();

	unsigned int nextMisoRFC();

	int checkMisoBSB(int tcb);

	void setMisoBSB(int tms);

	void addToCurMisoKeys(String& tck);

	bool isOnCurMisoKey(String& tmk);

	void removeFromCurMisoKeys(String& tck);

	void addToFinMisoKeys(String& tmp);

	bool hasCompletedMisoKey(String& tmk);

	void updateMissionSave(String& misoKey, const String& dbVar, String& varName, String& varData, bool doLock);

	void fillMissionSaveVars();

	void saveMissions();

	CraftingTool* getCurrentCraftingTool();

	CraftingTool* getCraftingTool(const int type, bool doLock);

	void setCurrentCraftingTool(CraftingTool* ct);

	void clearCurrentCraftingTool();

	void prepareCraftingSession(CraftingTool* ct, DraftSchematic* ds);

	void addIngredientToSlot(TangibleObject* tano, int slot, int counter);

	void removeResourceFromCraft(unsigned long long resID, int slot, int counter);

	void nextCraftingStage(String& test);

	void craftingCustomization(String& name, int condition, String& customizationString);

	void createPrototype(String& count);

	void createSchematic(String& count);

	void handleExperimenting(int count, int numRowsAttempted, String& expString);

	void sendDraftSchematics();

	void addDraftSchematicsFromGroupName(const String& schematicGroupName);

	void subtractDraftSchematicsFromGroupName(const String& schematicGroupName);

	void addDraftSchematic(DraftSchematic* ds);

	void subtractDraftSchematic(DraftSchematic* ds);

	unsigned int getDraftSchematicListSize();

	unsigned int getDraftSchematicUpdateCount(unsigned int count);

	DraftSchematic* getDraftSchematic(unsigned int schematicID);

	DraftSchematic* getDraftSchematic(int index);

	bool isChangingFactionStatus();

	Datapad* getDatapad();

	unsigned long long getNewItemID();

	unsigned int getItemShift();

	float getLastTestPositionX();

	float getLastTestPositionY();

	unsigned int getForcePower();

	unsigned int getForcePowerMax();

	bool isGuildLeader();

	unsigned long long getCurrentStructureID();

	void setCurrentStructureID(unsigned long long oid);

	SurveyTool* getSurveyTool();

	SurveyTool* getSampleTool();

	void setSurveyTool(SurveyTool* sTool);

	void setSampleTool(SurveyTool* sTool);

	void setSurveyWaypoint(WaypointObject* id);

	WaypointObject* getSurveyWaypoint();

	bool getCanSurvey();

	bool getCanSample();

	void setCanSurvey();

	void setCanSample();

	void clearFirstSampleEvent();

	void setSurveyEvent(String& resourcename);

	void setSampleEvent(String& resourcename, bool firstTime);

	void setCancelSample(bool val);

	bool getCancelSample();

	void sendSampleTimeRemaining();

	void setSurveyErrorMessage();

	void setSampleErrorMessage();

	bool getSurveyErrorMessage();

	bool getSampleErrorMessage();

	void sendMail(String& mailsender, UnicodeString& subjectSender, UnicodeString& bodySender, String& charNameSender);

	void setEntertainerEvent();

	void clearEntertainerEvent();

	void addEntertainerFlourishXp(int xp);

	void addEntertainerHealingXp(int xp);

	void setLastNpcConvStr(const String& conv);

	void setLastNpcConvMessStr(const String& mess);

	String& getLastNpcConvStr();

	String& getLastNpcConvMessStr();

	String& getLastNpcConvOption(int idx);

	void addLastNpcConvOptions(const String& option);

	void clearLastNpcConvOptions();

	int countLastNpcConvOptions();

	void setInputBoxReturnBuffer(const String& message);

	void setGuildLeader(bool guildLeader);

	void loadGuildChat();

	void setGuildPermissions(unsigned int bit);

	unsigned int getGuildPermissions();

	bool setGuildPermissionsBit(unsigned int bit, bool updateClient);

	void toggleGuildPermissionsBit(unsigned int bit);

	bool clearGuildPermissionsBit(unsigned int bit, bool updateClient);

	int getFactionPoints(const String& faction);

	void addFactionPoints(const String& faction, unsigned int points);

	void subtractFactionPoints(const String& faction, unsigned int points);

	int getFactionStatus();

	void setFactionStatus(int status);

	FactionPointList* getFactionList();

	unsigned int getMaxFactionPoints(String& faction);

	void delFactionPoints(Player* player, unsigned int amount);

	void updateWeather();

	void addSuiBoxChoice(String& choice);

	void removeLastSuiBoxChoice();

	void setSuiBoxChoices(SuiListBoxVector* choicesList);

	SuiListBoxVector* getSuiBoxChoices();

	void clearSuiBoxChoices();

	void setResourceDeedID(unsigned long long objectID);

	unsigned long long getResourceDeedID();

	void queueThrow(TangibleObject* throwItem, unsigned int actionCRC);

	void setImagedesignXpGiven(bool given);

	bool getImagedesignXpGiven();

	void teachPlayer(Player* player);

	void setTeachingOffer(String& sBox);

	void setTeacher(Player* player);

	void setStudent(Player* player);

	String& getTeachingOffer();

	Player* getTeacher();

	Player* getStudent();

	String& getTeachingSkillOption(int idx);

	void clearTeachingSkillOptions();

	void teachSkill(String& skillname);

	ActiveArea* getActiveArea();

	void setActiveArea(ActiveArea* area);

	void equipItem(TangibleObject* item);

	void unequipItem(TangibleObject* item);

	Armor* getPlayerArmor(int location);

protected:
	String _param0_queueFlourish__String_long_int_;
	String _param4_queueAction__Player_long_int_int_String_;
	String _param0_hasConsent__String_;
	String _param0_giveConsent__String_;
	String _param0_revokeConsent__String_;
	String _param0_trainSkillBox__String_bool_;
	String _param0_surrenderSkillBox__String_;
	String _param0_hasSkillBox__String_;
	String _param1_searchWaypoint__Player_String_int_;
	String _param2_queueHeal__TangibleObject_int_String_;
	String _param0_getXp__String_;
	String _param0_addXp__String_int_bool_;
	String _param0_removeXp__String_int_bool_;
	String _param0_loadXp__String_;
	String _param0_getXpTypeCap__String_;
	String _param0_calcPlayerLevel__String_;
	String _param0_sendSystemMessage__String_;
	UnicodeString _param0_sendSystemMessage__UnicodeString_;
	String _param0_sendSystemMessage__String_String_long_;
	String _param1_sendSystemMessage__String_String_long_;
	String _param0_sendSystemMessage__String_String_StfParameter_;
	String _param1_sendSystemMessage__String_String_StfParameter_;
	String _param0_setFirstName__String_;
	String _param0_setLastName__String_;
	String _param0_setFirstNameProper__String_;
	String _param0_setBiography__String_;
	UnicodeString _param0_setBiography__UnicodeString_;
	String _param0_setStartingProfession__String_;
	String _param0_setHairObject__String_;
	String _param0_setRaceFileName__String_;
	String _param0_setStartingLocation__String_;
	String _param0_checkCertification__String_;
	String _param0_addToCurMisoKeys__String_;
	String _param0_isOnCurMisoKey__String_;
	String _param0_removeFromCurMisoKeys__String_;
	String _param0_addToFinMisoKeys__String_;
	String _param0_hasCompletedMisoKey__String_;
	String _param0_updateMissionSave__String_String_String_String_bool_;
	String _param1_updateMissionSave__String_String_String_String_bool_;
	String _param2_updateMissionSave__String_String_String_String_bool_;
	String _param3_updateMissionSave__String_String_String_String_bool_;
	String _param0_nextCraftingStage__String_;
	String _param0_craftingCustomization__String_int_String_;
	String _param2_craftingCustomization__String_int_String_;
	String _param0_createPrototype__String_;
	String _param0_createSchematic__String_;
	String _param2_handleExperimenting__int_int_String_;
	String _param0_addDraftSchematicsFromGroupName__String_;
	String _param0_subtractDraftSchematicsFromGroupName__String_;
	String _param0_setSurveyEvent__String_;
	String _param0_setSampleEvent__String_bool_;
	String _param0_sendMail__String_UnicodeString_UnicodeString_String_;
	UnicodeString _param1_sendMail__String_UnicodeString_UnicodeString_String_;
	UnicodeString _param2_sendMail__String_UnicodeString_UnicodeString_String_;
	String _param3_sendMail__String_UnicodeString_UnicodeString_String_;
	String _param0_setLastNpcConvStr__String_;
	String _param0_setLastNpcConvMessStr__String_;
	String _param0_addLastNpcConvOptions__String_;
	String _param0_setInputBoxReturnBuffer__String_;
	String _param0_getFactionPoints__String_;
	String _param0_addFactionPoints__String_int_;
	String _param0_subtractFactionPoints__String_int_;
	String _param0_getMaxFactionPoints__String_;
	String _param0_addSuiBoxChoice__String_;
	String _param0_setTeachingOffer__String_;
	String _param0_teachSkill__String_;
};

class PlayerHelper : public DistributedObjectClassHelper, public Singleton<PlayerHelper> {
	static PlayerHelper* staticInitializer;

public:
	PlayerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<PlayerHelper>;
};

#include "../creature/CreatureObjectImplementation.h"

class PlayerServant : public CreatureObjectImplementation {
public:
	Player* _this;

public:
	PlayerServant(unsigned long long oid);
	virtual ~PlayerServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*PLAYER_H_*/
