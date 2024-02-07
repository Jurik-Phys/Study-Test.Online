import style from './UserResultTest.module.css'
import { useNavigate } from "react-router-dom"

const UserResultTest = () => {
  const navigate = useNavigate();

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>Test results</div>
        <div className={style.text}>
          <div>
            <label className={style.sText}>
              Life Safety. Subsection 1
            </label>
            <ul>
              <li>
                <label className={style.sText}>
                  Annotation.
                </label> It is the activity of annotating something. She retained a number of copies for further annotation
              </li>
              <li>
                <label className={style.sText}>
                  Count of questions:
                </label> 25
              </li>
              <li>
                <label className={style.sText}>
                  Begin:
                </label> 11:00 02-02-2024
              </li>
              <li>
                <label className={style.sText}>
                  End:
                </label> 11:43 02-02-2024
              </li>
              <li>
                <label className={style.sText}>
                  Result:
                </label> 4.6
              </li>
            </ul>
          </div>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate("/")} >Close</button>
        </div>
      </div>
  );
}

export default UserResultTest;
