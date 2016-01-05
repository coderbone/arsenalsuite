# Introduction #

These are my very poor notes on the process of adding job types to Arsenal "the long way," which includes recompiling from the source. The "short way" would be to use python plug-ins, however, I don't know much about that.

# Details #

  1. Add a New Class into the Schema
    1. Run Classmaker
    1. Open `cpp/lib/classes/schema.xml`
    1. Right-click on the 'Job' entry and choose 'Create Inherited table'
    1. Enter in JobJOBTYPE in Table Name and Class Name and choose OK, where JOBTYPE is the name of the new job type
    1. Click on 'Create Database'
    1. Click 'Create'
  1. Add database triggers
    1. Open `sql/renderfarm/job_triggers.sql`
    1. Add Codebits/Triggers (see below) where JOBTYPE is the name of the new job type
    1. Run the CREATE Codebits/Triggers in psql
  1. Add job service entry to database
    1. `insert into service (service,enabled) values ('JOBTYPE',true);` where JOBTYPE is the name of the new job type.
    1. `insert into jobtype (jobtype,fkeyservice) values ('JOBTYPE',SERVICEKEY);` where SERVICEKEY is the keyservice from the entry added into service.
  1. Create a Burner
    1. <details omitted>
  1. Rebuild the Arsenal Suite

# Codebits #
## Triggers ##
```
DROP TRIGGER IF EXISTS JobJOBTYPE_Update ON jobJOBTYPE;
CREATE TRIGGER JobJOBTYPE_Update BEFORE UPDATE ON JobJOBTYPE FOR EACH ROW EXECUTE PROCEDURE Job_Update();
DROP TRIGGER IF EXISTS JobJOBTYPE_Insert ON jobJOBTYPE;
CREATE TRIGGER JobJOBTYPE_Insert AFTER INSERT ON JobJOBTYPE FOR EACH ROW EXECUTE PROCEDURE Job_Insert();
DROP TRIGGER IF EXISTS JobJOBTYPE_Delete ON jobJOBTYPE;
CREATE TRIGGER JobJOBTYPE_Delete AFTER DELETE ON JobJOBTYPE FOR EACH ROW EXECUTE PROCEDURE Job_Delete();
```